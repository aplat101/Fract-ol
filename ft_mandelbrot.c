/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mandelbrot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 16:56:14 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 06:06:58 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_refresh_mandel_values(t_win *w)
{
	w->zr = 0;
	w->zi = 0;
	w->cr = w->i->x / w->zoom + w->x1;
	w->ci = w->i->y / w->zoom + w->y1;
	w->iter = -1;
}

void		ft_start_mandelbrot(t_win *w)
{
	int		i;

	i = 0;
	while (i < THREAD)
	{
		w->it = i;
		if (pthread_create(&w->t[i], NULL, mandelbrot, w) == -1)
		{
			perror("pthread_create");
			return ;
		}
		pthread_join(w->t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
	ft_create_info(w);
}

void		*mandelbrot(void *arg)
{
	double	tmp;
	t_win	*w;

	w = arg;
	w->i->x = POST / THREAD * w->it - 1;
	while (++(w->i->x) < (POST / THREAD * (w->it + 1)))
	{
		w->i->y = -1;
		while (++(w->i->y) < HH)
		{
			ft_refresh_mandel_values(w);
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++(w->iter) < w->iter_max)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			if (w->i->y < HH && w->i->y >= 0 && w->i->x >= 0 && w->i->x < POST)
			{
				if (w->iter == w->iter_max)
					w->img[(int)((w->i->y * POST) + w->i->x)] = 0;
				else
					w->img[(int)((w->i->y * POST) + w->i->x)] = 0x0F100A * w->iter;
			}
		}
	}
	pthread_exit(0);
}
