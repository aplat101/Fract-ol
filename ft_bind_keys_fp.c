/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys_fp.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 08:05:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 14:01:57 by aplat       ###    #+. /#+    ###.fr     */
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

void	ft_iterm(t_win *w)
{
	if (w->iter - 2 <= 10)
		w->iter = 10;
	else
		w->iter -= 2;
	ft_start_fract(w);
}

void	ft_iterp(t_win *w)
{
	w->iter += 2;
	ft_start_fract(w);
}

void	ft_zoomp(t_win *w, int x, int y)
{
	w->x1 = ((double)x / w->zoom + w->x1) - (x / (w->zoom * 1.3));
	w->y1 = ((double)y / w->zoom + w->y1) - (y / (w->zoom * 1.3));
	w->x2 = ((double)x / w->zoom + w->x2) - (x / (w->zoom * 1.3));
	w->y2 = ((double)y / w->zoom + w->y2) - (y / (w->zoom * 1.3));
	w->zoom *= 1.3;
	w->iter++;
	ft_start_fract(w);
}

void	ft_zoomm(t_win *w, int x, int y)
{
	if (w->zoom == 100)
		return ;
	w->x1 = ((double)x / w->zoom + w->x1) - (x / (w->zoom / 1.3));
	w->y1 = ((double)y / w->zoom + w->y1) - (y / (w->zoom / 1.3));
	w->x2 = ((double)x / w->zoom + w->x2) - (x / (w->zoom / 1.3));
	w->y2 = ((double)y / w->zoom + w->y2) - (y / (w->zoom / 1.3));
	if (w->zoom / 1.3 < 100)
		w->zoom = 100;
	else
		w->zoom /= 1.3;
	if (w->iter - 1 <= 10)
		w->iter = 10;
	else
		w->iter--;
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

void	ft_swap_multi(t_win *w)
{
	int	res;

	res = w->flat;
	if (res == 0)
		w->flat = 1;
	else
		w->flat = 0;
	ft_start_fract(w);
}
