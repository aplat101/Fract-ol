/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys_fp.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 08:05:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 11:03:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int	key_press_w1(int keycode, t_env *env)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(env->ptr, env->fp->win);
		if (env->ds == 0)
			exit(0);
		env->ds = 0;
		return (0);
	}
	if (keycode == K_LEFT)
		ft_move_left(env->fp);
	if (keycode == K_RIGHT)
		ft_move_right(env->fp);
	if (keycode == K_DOWN)
		ft_move_down(env->fp);
	if (keycode == K_UP)
		ft_move_up(env->fp);
	return (0);
}

int	key_release_w1(int keycode, t_env *env)
{
/*	if (keycode == K_C)
		ft_center(env->fp);*/
	if (keycode == K_PAD_PLUS)
		ft_iterp(env->fp);
	if (keycode == K_PAD_MINUS)
		ft_iterm(env->fp);
	return (0);
}

int	mouse_press_w1(int button, int x, int y, t_env *env)
{
	y = x;
	if (button == M_WHEELDOWN)
		ft_zoomp(env->fp);
	if (button == M_WHEELUP)
		ft_zoomm(env->fp);
	return (0);
}

void	ft_iterm(t_win *w)
{
	if (w->iter - 5 <= 5)
		w->iter = 5;
	else
		w->iter -= 5;
	ft_start_fract(w);
}

void	ft_iterp(t_win *w)
{
	w->iter += 5;
	ft_start_fract(w);
}

void	ft_zoomp(t_win *w)
{
	w->zoom += 5;
	ft_start_fract(w);
}

void	ft_zoomm(t_win *w)
{
	w->zoom -= 5;
	ft_start_fract(w);
}