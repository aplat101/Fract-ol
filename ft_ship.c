/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ship.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 16:56:42 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 14:29:04 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_start_ship(t_win *w)
{
	int		i;

	ft_reset_img(w);
	i = 0;
	while (i < THREAD)
	{
		w->it = i;
		if (pthread_create(&w->t[i], NULL, &ship, w) == -1)
		{
			perror("pthread_create");
			return ;
		}
		pthread_join(w->t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
}

void		*ship(void *arg)
{
	double	tmp;
	int		i;
	t_win	*w;
	double	x;
	double	y;

	w = arg;
	x = POST / THREAD * w->it - 1;
	while (++x < (POST / THREAD * (w->it + 1)))
	{
		y = -1;
		while (++y < HH)
		{
			ft_refresh_mandel_values(w, x, y);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = fabs(2 * w->zi * tmp) + w->ci;
			}
			if (y < HH && y >= 0 && x >= 0 && x < POST)
			{
				if (i == w->iter)
					w->img[(int)((y * POST) + x)] = 0;
				else
					w->img[(int)((y * POST) + x)] = 0x0F100A * i;
			}
		}
	}
	pthread_exit(0);
}
