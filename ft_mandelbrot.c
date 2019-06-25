/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mandelbrot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 15:21:50 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 15:00:59 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_refresh_mandel_values(t_win *w)
{
	w->cr = w->lx / w->zoom + w->x1;
	w->ci = w->ly / w->zoom + w->y1;
	w->zr = 0;
	w->zi = 0;
}

void		ft_mandelbrot(t_win *w)
{
	float	tmp;
	int		i;

	w->lx = -1;
	while (++(w->lx) < w->imagex - 1)
	{
		w->ly = -1;
		while (++(w->ly) < w->imagey - 1)
		{
			ft_refresh_mandel_values(w);
			i = -1; 
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			if (i == w->iter && ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = 0;
			else if (ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = (0 | 0 | (i * 255) / w->iter);
		}
	}
}