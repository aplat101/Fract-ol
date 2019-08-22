/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 06:13:03 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 08:04:38 by aplat       ###    #+. /#+    ###.fr     */
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
	w->img_ptr = mlx_new_image(w->ptr, WD, HH);
	w->img = (int*)mlx_get_data_addr(w->img_ptr, &(bpp), &(s_l), &(endian));
}

void	ft_mlx_keys(t_env *env)
{
	mlx_hook(env->fp->win, 2, 0, key_press_w1, env);
	mlx_hook(env->fp->win, 3, 0, key_release_w1, env);
	mlx_hook(env->fp->win, 4, 0, mouse_press_w1, env);
	mlx_hook(env->fp->win, 17, (1L << 17), close_cross, env);
	if (env->ds == 1)
	{
		mlx_hook(env->sp->win, 2, 0, key_press_w2, env);
		mlx_hook(env->sp->win, 3, 0, key_release_w2, env);
		mlx_hook(env->sp->win, 4, 0, mouse_press_w2, env);
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