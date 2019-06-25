/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fract.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:03:43 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 14:59:44 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset_values(t_win *w)
{
	w->imagex = (w->x2 - w->x1) * w->zoom;
	w->imagey = (w->y2 - w->y1) * w->zoom;
	w->lx = -1;
	w->ly = -1;
	w->projx = POST - w->imagex;
	w->projy = HH - w->imagey;
}

void	ft_init_switch(t_env *env)
{
	if (env->ds == 1)
	{
		ft_init_fract_values(env->fp);
		ft_init_fract_values(env->sp);
	}
	else
		ft_init_fract_values(env->fp);
}

void	ft_init_fract_values(t_win *w)
{
	w->iter = 64;
	w->x1 = -1.5;
	w->y1 = -1.5;
	w->x2 = 1.5;
	w->y2 = 1.5;
	w->zoom = 400;
	ft_reset_values(w);
	ft_start_fract(w);
}

void	ft_start_fract(t_win *w)
{
	ft_new_img(w);
	if (ft_strcmp(w->name, JULIA) == 0)
		ft_julia(w);
	if (ft_strcmp(w->name, MANDEL) == 0)
		ft_mandelbrot(w);
	if (ft_strcmp(w->name, SHIP) == 0)
		ft_ship(w);
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
}