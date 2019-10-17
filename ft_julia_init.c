/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 06:10:58 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 16:43:28 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			ft_in_img(t_win *w)
{
	int		res;
	double	y;
	double	x;

	y = w->ly + w->projy;
	x = w->lx + w->projx;
	res = 0;
	if ((x < ((WD / THREAD * (w->it + 1))) && x > ((WD / THREAD * w->it)))
			&& (y < HH && y > 0 && x > 0 && x < WD))
		res = 1;
	else if (y < HH && y > 0 && x > 0 && x < WD)
		res = 1;
	else
		res = 0;
	return (res);
}

void		ft_refresh_julia_values(t_win *w)
{
	w->zr = w->lx / w->zoomx + w->x1;
	w->zi = w->ly / w->zoomy + w->y1;
	w->cr = w->mouse_x;
	w->ci = w->mouse_y;
}

void		ft_start_julia(t_win *w)
{
	int		i;

	ft_reset_img(w);
	w->imagex = (w->x2 - w->x1) * w->zoomx;
	w->imagey = (w->y2 - w->y1) * w->zoomy;
	i = 0;
	while (i < THREAD)
	{
		w->it = i;
		if (pthread_create(&w->t[i], NULL, julia, w) == -1)
		{
			perror("pthread_create");
			return ;
    	}
		pthread_join(w->t[i], NULL);
		i++;
	}
}

void		ft_reset_img(t_win *w)
{
	int 	i;
	int		j;

	i = 0;
	while (i < HH)
	{
		j = 0;
		while (j < WD)
		{
			w->img[(int)((i * WD) + j)] = 0;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
}

void	*julia(void *arg)
{
	double	tmp;
	int		i;
	t_win	*w;

	w = arg;
	w->lx = (w->imagex / THREAD * w->it) - 1;
	while (++(w->lx) < (w->imagex / THREAD * (w->it + 1)))
	{
		w->ly = 0;
		while (w->ly < w->imagey)
		{
			ft_refresh_julia_values(w);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			ft_getcolor(w, i);
		}
	}
	pthread_exit(0);
}

void			ft_getcolor(t_win *w, int i)
{
	if (i == w->iter && ft_in_img(w) == 1)
		w->img[(int)(((w->ly + w->projy) * WD) + w->lx + w->projx)] = 0;
	else if (ft_in_img(w) == 1)
		w->img[(int)(((w->ly + w->projy) * WD) + w->lx + w->projx)] = 0x0F100A * i;
	w->ly++;
}
