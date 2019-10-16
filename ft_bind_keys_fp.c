/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys_fp.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 08:05:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 09:54:42 by aplat       ###    #+. /#+    ###.fr     */
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
	if (keycode == K_S)
		ft_swap_fract(env->fp);
	if (keycode == K_V)
		ft_variant_julia(env->fp);
	return (0);
}

int	mouse_press_w1(int button, int x, int y, t_env *env)
{
	if (button == M_WHEELDOWN)
		ft_zoomp1(env->fp, x, y);
	if (button == M_WHEELUP)
		ft_zoomm1(env->fp, x, y);
	return (0);
}

int	mouse_move_w1(int x, int y, t_env *env)
{
	if (env->fp->variant == 1 && ft_strcmp(env->fp->name, JULIA) == 0)
	{
		env->fp->mouse_x = (double)(x - (WD / 2)) / (WD / 4);
		env->fp->mouse_y = (double)(y - (HH / 2)) / (WD / 4);
	}
	ft_start_fract(env->fp);
	return (0);
}

void	ft_iterm(t_win *w)
{
	if (w->iter - 5 <= 10)
		w->iter = 10;
	else
		w->iter -= 5;
	ft_start_fract(w);
}

void	ft_iterp(t_win *w)
{
	w->iter += 5;
	ft_start_fract(w);
}

void	ft_zoomp1(t_win *w, int x, int y)
{
//	printf("X ==> %d\nY ==> %d\n", x, y);
	x = y;
	w->zoomx += 10;
	w->zoomy += 10;
	ft_start_fract(w);
}

void	ft_zoomm1(t_win *w, int x, int y)
{
//	printf("X ==> %d\nY ==> %d\n", x, y);
	x = y;
	w->zoomy -= 10;
	w->zoomx -= 10;
	ft_start_fract(w);
}

void	ft_zoomp(t_win *w, int x, int y)
{
	double	dx;
	double	dy;

	dx = w->x2 - w->x1;
	dy = w->y2 - w->y1;
	w->zoomx = ((double)x / WD * dx) - dx / 2 + w->zoomx;
    w->zoomy = ((double)y / HH * dy) - dy / 2 + w->zoomy;
	if (x >= 0 && x < WD)
	{
		w->x2 = w->zoomx + (dx / 1.3) / 2;
		w->x1 = w->zoomx - (dx / 1.3) / 2;
		w->y2 = w->zoomy + (dy / 1.3) / 2;
		w->y1 = w->zoomy - (dy / 1.3) / 2;
	}
	ft_start_fract(w);
}

void	ft_zoomm(t_win *w, int x, int y)
{
	double	dx;
	double	dy;

	dx = w->x2 - w->x1;
	dy = w->y2 - w->y1;
	w->zoomx = ((double)x / WD * dx) - dx / 2 + w->zoomx;
    w->zoomy = ((double)y / HH * dy) - dy / 2 + w->zoomy;
	if (x >= 0 && x < WD)
	{
		w->x2 = w->zoomx + (dx * 1.3) / 2;
		w->x1 = w->zoomx - (dx * 1.3) / 2;
		w->y2 = w->zoomy + (dy * 1.3) / 2;
		w->y1 = w->zoomy - (dy * 1.3) / 2;
	}
	ft_start_fract(w);
}

void	ft_variant_julia(t_win *w)
{
	int	res;

	res = w->variant;
	if (res == 0)
		w->variant = 1;
	else
		w->variant = 0;
	ft_start_fract(w);
}