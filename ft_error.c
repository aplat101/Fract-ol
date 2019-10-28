/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 15:21:44 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 22:31:40 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_values(t_win *w)
{
	w->zoom = 250;
	w->mouse_x = 0;
	w->mouse_y = 0;
	w->iter_max = 10;
	w->x1 = -2;
	w->y1 = -2;
	w->x2 = 2;
	w->y2 = 2;
	w->variant = 0;
	w->flat = 0;
	if (!(w->i = malloc(sizeof(t_point))))
		return ;
	w->i->x = 0;
	w->i->y = 0;
}

int		ft_check_exist(int ac, char **av)
{
	int res;

	res = 0;
	ft_strcmp(av[ac], "Julia") == 0 ? res++ : 0;
	ft_strcmp(av[ac], "Mandelbrot") == 0 ? res++ : 0;
	ft_strcmp(av[ac], "Ship") == 0 ? res++ : 0;
	return (res);
}

void	ft_usage(void)
{
	ft_putstr("Fractals Available : Julia / Mandelbrot / Ship \n");
	exit(0);
}

void	ft_check_arg(char **av, int ac, t_env *env)
{
	if (ft_check_exist(ac, av) == 1 && ft_check_exist(ac - 1, av) == 1
		&& ac == 2)
	{
		ft_alloc_win(ac, env);
		ft_create_window(env->fp);
		ft_create_window(env->sp);
		env->fp->name = av[1];
		env->sp->name = av[2];
		ft_set_values(env->fp);
		ft_set_values(env->sp);
		ft_start_fract(env->fp);
		ft_start_fract(env->sp);
	}
	else if (ac == 1 && ft_check_exist(ac, av) == 1)
	{
		ft_alloc_win(ac, env);
		ft_create_window(env->fp);
		env->fp->name = av[1];
		ft_set_values(env->fp);
		ft_start_fract(env->fp);
	}
	else
		ft_usage();
}

void	ft_alloc_win(int ac, t_env *env)
{
	if (!(env->fp = malloc(sizeof(t_win))))
		return ;
	env->ds = 0;
	if (ac == 2)
	{
		if (!(env->sp = malloc(sizeof(t_win))))
			return ;
		env->sp->ptr = env->ptr;
		env->ds = 1;
	}
	env->fp->ptr = env->ptr;
}
