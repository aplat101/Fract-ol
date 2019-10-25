/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fract.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:37:40 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 11:26:59 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start_fract(t_win *w)
{
	if (ft_strcmp(w->name, JULIA) == 0)
		ft_start_julia(w);
	if (ft_strcmp(w->name, MANDEL) == 0)
		ft_start_mandelbrot(w);
	if (ft_strcmp(w->name, SHIP) == 0)
		ft_start_ship(w);
}
