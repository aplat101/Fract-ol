/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 06:13:03 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 14:29:55 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_window(t_win *w)
{
	int	bpp;
	int	s_l;
	int	endian;

	w->win = mlx_new_window(w->ptr, WD, HH, "Fract'ol");
	w->img_ptr = mlx_new_image(w->ptr, POST, HH);
	w->img = (int*)mlx_get_data_addr(w->img_ptr, &(bpp), &(s_l), &(endian));
}

void	ft_mlx_keys(t_env *env)
{
	mlx_hook(env->fp->win, 2, 0, key_press_w1, env);
	mlx_hook(env->fp->win, 3, 0, key_release_w1, env);
	mlx_hook(env->fp->win, 4, 0, mouse_press_w1, env);
	mlx_hook(env->fp->win, 6, 0, mouse_move_w1, env);
	mlx_hook(env->fp->win, 17, (1L << 17), close_cross, env);
	if (env->ds == 1)
	{
		mlx_hook(env->sp->win, 2, 0, key_press_w2, env);
		mlx_hook(env->sp->win, 3, 0, key_release_w2, env);
		mlx_hook(env->sp->win, 4, 0, mouse_press_w2, env);
		mlx_hook(env->sp->win, 6, 0, mouse_move_w2, env);
		mlx_hook(env->sp->win, 17, (1L << 17), close_cross, env);
	}
	mlx_loop(env->ptr);
}

int		close_cross(t_env *env)
{
	if (env->ds == 0)
		exit(0);
	env->ds = 0;
	return (0);
}

void	ft_swap_fract(t_win *w)
{
	int	fract;

	fract = 0;
	if (ft_strcmp(w->name, JULIA) == 0)
		fract = 1;
	if (ft_strcmp(w->name, MANDEL) == 0)
		fract = 2;
	if (ft_strcmp(w->name, SHIP) == 0)
		fract = 3;
	fract == 1 ? w->name = MANDEL : 0;
	fract == 2 ? w->name = SHIP : 0;
	fract == 3 ? w->name = JULIA : 0;
	ft_start_fract(w);
}

void	ft_reset_values(t_win *w)
{
	w->zoom = 250;
	w->iter = 10;
	w->x1 = -2;
	w->y1 = -2;
	w->x2 = 2;
	w->y2 = 2;
	w->variant = 0;
	ft_start_fract(w);
}