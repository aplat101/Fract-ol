/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 17:22:01 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 15:01:44 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_center(t_win *w)
{
	ft_reset_values(w);
	ft_start_fract(w);
}

int			ft_in_img(t_win *w)
{
	int		res;
	float	y;
	float	x;

	y = w->ly + w->projy;
	x = w->lx + w->projx;
	res = 0;
	if ((y < HH && y > 0) && (x < POST && x > 0))
		res = 1;
	else
		res = 0;
	return (res);
}