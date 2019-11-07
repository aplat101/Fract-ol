/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fract.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:37:40 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 06:02:38 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_start_fract(t_win *w)
{
	if (ft_strcmp(w->name, JULIA) == 0)
		ft_start_julia(w);
	if (ft_strcmp(w->name, MANDEL) == 0)
		ft_start_mandelbrot(w);
	if (ft_strcmp(w->name, SHIP) == 0)
		ft_start_ship(w);
}

void		ft_set_values(t_win *w)
{
	w->zoom = 250;
	w->mouse_x = 0;
	w->mouse_y = 0;
	w->iter_max = 10;
	w->x1 = -2;
	w->y1 = -2;
	w->x2 = 2;
	w->y2 = 2;
	w->variant = 0;
	w->flat = 0;
	if (!(w->i = malloc(sizeof(t_point))))
		return ;
	w->i->x = 0;
	w->i->y = 0;
	w->ret = 0;
}

void		ft_reset_values(t_win *w)
{
	ft_reset_img(w);
	w->zoom = 250;
	w->iter_max = 10;
	w->x1 = -2;
	w->y1 = -2;
	w->x2 = 2;
	w->y2 = 2;
	w->variant = 0;
	ft_start_fract(w);
}
