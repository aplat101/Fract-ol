/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 06:10:58 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 14:57:07 by aplat       ###    #+. /#+    ###.fr     */
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
	if ((y < HH && y > 0) && (x < ((WD / 5 * (w->it + 1))) && x > 0))
		res = 1;
	else
		res = 0;
	return (res);
}

void		ft_refresh_julia_values(t_win *w)
{
	w->zr = w->lx / w->zoom + w->x1;
	w->zi = w->ly / w->zoom + w->y1;
	w->cr = -0.577;
	w->ci = 0.478;
}

void		ft_start_julia(t_win *w)
{
	int		i;

	ft_reset_img(w);
	i = 0;
	while (i < 5)
	{
		w->it = i;
		if(pthread_create(&w->t[i], NULL, julia, w) == -1) 
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
}

void	*julia(void *arg)
{
	double	tmp;
	int		i;
	t_win	*w;

	w = arg;
	w->lx = WD / 5 * w->it;
	while (w->lx < (WD / 5 * (w->it + 1)))
	{
		w->ly = -1;
		while (++(w->ly) < HH)
		{
			ft_refresh_julia_values(w);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			if (i == w->iter && ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * WD) + w->lx + w->projx)] = 255;
			else if (ft_in_img(w) == 1 && i < w->iter)
				w->img[(int)(((w->ly + w->projy) * WD) + w->lx + w->projx)] = (0 | 0 | (i * 255) / w->iter);
		}
		w->lx++;
	}
	pthread_exit(0);
}