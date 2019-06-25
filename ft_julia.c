/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 21:51:20 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 15:02:42 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_refresh_julia_values(t_win *w)
{
	w->zr = w->lx / w->zoom + w->x1;
	w->zi = w->ly / w->zoom + w->y1;
	w->cr = -0.8;
	w->ci = 0.156;
}

void		ft_julia(t_win *w)
{
	float	tmp;
	int		i;

	w->lx = -1;
	while (++(w->lx) < w->imagex - 1)
	{
		w->ly = -1;
		while (++(w->ly) < w->imagey - 1)
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
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = 0;
			else if (ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = (0 | 0 | (i * 255) / w->iter);
		}
	}
}