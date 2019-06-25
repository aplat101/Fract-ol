/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_window.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:17:13 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 14:31:11 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void    ft_create_window(t_env *env)
{
    int	bpp;
	int	s_l;
	int	endian;

	env->ptr = mlx_init();
	env->fp->win = mlx_new_window(env->ptr, WD, HH, "Fract'ol");
	env->fp->img_ptr = mlx_new_image(env->ptr, (int)POST, HH);
	env->fp->img = (int*)mlx_get_data_addr(env->fp->img_ptr, &(bpp), &(s_l), &(endian));
	env->fp->ptr = env->ptr;
	ft_create_info(env->fp, env);
	ft_frame(env->fp);
    if (env->ds == 1)
	{
		env->sp->win= mlx_new_window(env->ptr, WD, HH, "Fract'ol");
		env->sp->img_ptr = mlx_new_image(env->ptr, (int)POST, HH);
		env->sp->img = (int*)mlx_get_data_addr(env->sp->img_ptr, &(bpp), &(s_l), &(endian));
		ft_create_info(env->sp, env);
		ft_frame(env->sp);
		env->sp->ptr = env->ptr;
	}
}

void	ft_create_info(t_win *win, t_env *env)
{
	int		bpp;
	int		s_l;
	int		endian;

	win->info_ptr = mlx_new_image(env->ptr, TIN, HH);
	win->info = (int*)mlx_get_data_addr(win->info_ptr, &(bpp), &(s_l), &(endian));
}

void		ft_frame(t_win *w)
{
	int		i;

	i = -1;
	while (++i < TIN)
	{
		w->info[i] = RED;
		w->info[(int)(TIN) + i] = RED;
		w->info[(int)(2 * TIN) + i] = RED;
		w->info[(int)((HH - 1) * TIN) + i] = RED;
		w->info[(int)((HH - 2) * TIN) + i] = RED;
		w->info[(int)((HH - 3) * TIN) + i] = RED;
	}
	i = -1;
	while (++i < HH)
	{
		w->info[(int)(i * TIN)] = RED;
		w->info[(int)(i * TIN) + 1] = RED;
		w->info[(int)(i * TIN) + 2] = RED;
		w->info[(int)((i * TIN) + ((TIN) - 1))] = RED;
		w->info[(int)((i * TIN) + ((TIN) - 1)) - 1] = RED;
		w->info[(int)((i * TIN) + ((TIN) - 1)) - 2] = RED;
	}
	mlx_put_image_to_window(w->info, w->win, w->info_ptr, POST, 0);
//	ft_fill_frame(win);
}