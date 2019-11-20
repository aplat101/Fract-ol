/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 11:26:22 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 11:02:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_refresh_julia_values(t_win *w)
{
	w->zr = w->i->x / w->zoom + w->x1;
	w->zi = w->i->y / w->zoom + w->y1;
	w->iter = -1;
}

void		ft_start_julia(t_win *w)
{
	int		i;

	w->cr = w->mouse_x;
	w->ci = w->mouse_y;
	w->iter = -1;
	i = -1;
	while (++i < THREAD)
	{
		w->it = i;
		w->ret = (POST / THREAD * (w->it + 1));
		if (pthread_create(&w->t[i], NULL, julia, w) == -1)
		{
			perror("pthread_create");
			return ;
		}
		pthread_join(w->t[i], NULL);
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
	ft_create_info(w);
}

void		*julia(void *arg)
{
	double	tmp;
	t_win	*w;

	w = arg;
	w->i->x = POST / THREAD * w->it - 1;
	while (++(w->i->x) < w->ret)
	{
		w->i->y = -1;
		while (++(w->i->y) < HH)
		{
			ft_refresh_julia_values(w);
			while ((w->zr * w->zr + w->zi * w->zi) < 4 &&
				++(w->iter) < w->iter_max)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			ft_get_color(w);
		}
	}
	pthread_exit(0);
}
