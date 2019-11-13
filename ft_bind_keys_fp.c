/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys_fp.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 08:05:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 23:24:36 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_w1(int keycode, t_env *env)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(env->ptr, env->fp->win);
		if (env->ds == 0)
			exit(0);
		env->ds = 0;
		return (0);
	}
	if (keycode == K_PAD_PLUS)
		ft_iterp(env->fp);
	if (keycode == K_PAD_MINUS)
		ft_iterm(env->fp);
	return (0);
}

int		key_release_w1(int keycode, t_env *env)
{
	if (keycode == K_S)
		ft_swap_fract(env->fp);
	if (keycode == K_V)
		ft_variant_julia(env->fp);
	if (keycode == K_R)
		ft_reset_values(env->fp);
	if (keycode == K_F)
		ft_swap_multi(env->fp);
	if (keycode == K_C)
		ft_swap_color(env->fp);
	return (0);
}

int		mouse_press_w1(int button, int x, int y, t_env *env)
{
	if (button == M_WHEELDOWN)
		ft_zoomp(env->fp, x, y);
	if (button == M_WHEELUP)
		ft_zoomm(env->fp, x, y);
	return (0);
}

int		mouse_move_w1(int x, int y, t_env *env)
{
	if (env->fp->variant == 1 && ft_strcmp(env->fp->name, JULIA) == 0)
	{
		env->fp->mouse_x = (double)(x - (WD / 2)) / (WD / 4);
		env->fp->mouse_y = (double)(y - (HH / 2)) / (WD / 4);
	}
	ft_start_fract(env->fp);
	return (0);
}
