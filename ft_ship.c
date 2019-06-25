/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ship.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 13:20:41 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 15:03:34 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_ship(t_win *w)
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
				w->zi = fabs(2 * w->zi * tmp) + w->ci;
			}
			if (i == w->iter && ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = 0;
			else if (ft_in_img(w) == 1)
				w->img[(int)(((w->ly + w->projy) * POST) + w->lx + w->projx)] = (0 | 0 | (i * 255) / w->iter);
		}
	}
}