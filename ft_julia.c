/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 11:26:22 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 23:45:20 by aplat       ###    #+. /#+    ###.fr     */
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

	ft_create_info(w);
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
}

void	*julia(void *arg)
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
			while ((w->zr * w->zr + w->zi * w->zi) < 4 && ++(w->iter) < w->iter_max)
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

/*void	julia_flat(t_win *w)
{
	double	tmp;
	int		i;
	double	x;
	double	y;

	x = -1;
	while (++x < POST)
	{
		y = -1;
		while (++y < HH)
		{
			ft_refresh_julia_values(w, x, y);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
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
}
*/
/*void	ft_getcolor(t_win *w, int i)
{
	if (i == w->iter && ft_in_img(w) == 1)
		w->img[(int)(((y + w->projy) * POST) + x + w->projx)] = 0;
	else if (ft_in_img(w) == 1)
		w->img[(int)(((y + w->projy) * POST) + x + w->projx)] = 0x0F100A * i;
	y++;
}*/
