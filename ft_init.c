/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:54:01 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 13:19:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fract(t_env *env)
{
	env->ptr = mlx_init();
	env->fract[0] = JULIA;
	env->fract[1] = MANDEL;
	env->fract[2] = SHIP;
	env->nbfract = 3;
	env->ds = 0;
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
	(void)env;
	if (env->ds == 0)
		exit(0);
	env->ds = 0;
	return (0);
}

void		ft_new_img(t_win *w)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx_destroy_image(w->ptr, w->img_ptr);
	w->img_ptr = mlx_new_image(w->ptr, POST, HH);
	w->img = (int*)mlx_get_data_addr(w->img_ptr, &(bpp), &(s_l), &(endian));
	mlx_destroy_image(w->ptr, w->info_ptr);
	w->info_ptr = mlx_new_image(w->ptr, TIN, HH);
	w->info =
	(int*)mlx_get_data_addr(w->info_ptr, &(bpp), &(s_l), &(endian));
}