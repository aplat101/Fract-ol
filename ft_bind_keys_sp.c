/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys_sp.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 08:06:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 13:59:48 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int	key_press_w2(int keycode, t_env *env)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(env->ptr, env->sp->win);
		if (env->ds == 0)
			exit(0);
		env->ds = 0;
		return (0);
	}
	if (keycode == K_LEFT)
		ft_move_left(env->sp);
	if (keycode == K_RIGHT)
		ft_move_right(env->sp);
	if (keycode == K_DOWN)
		ft_move_down(env->sp);
	if (keycode == K_UP)
		ft_move_up(env->sp);
	if (keycode == K_PAD_PLUS)
		ft_iterp(env->sp);
	if (keycode == K_PAD_MINUS)
		ft_iterm(env->sp);
	return (0);
}

int	key_release_w2(int keycode, t_env *env)
{
	if (keycode == K_S)
		ft_swap_fract(env->sp);
	if (keycode == K_V)
		ft_variant_julia(env->sp);
	return (0);
}

int	mouse_press_w2(int button, int x, int y, t_env *env)
{
	if (button == M_WHEELDOWN)
		ft_zoomp1(env->sp, x, y);
	if (button == M_WHEELUP)
		ft_zoomm1(env->sp, x, y);
	return (0);
}

int	mouse_move_w2(int x, int y, t_env *env)
{
	if (env->sp->variant == 1)
	{
		env->sp->mouse_x = (double)(x - (WD / 2)) / (WD / 4);
		env->sp->mouse_y = (double)(y - (HH / 2)) / (WD / 4);
	}
	ft_start_fract(env->sp);
	return (0);
}
