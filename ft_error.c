/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:48:25 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:29:03 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		ft_check_exist(int ac, char **av, t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nbfract)
	{
		if (ft_strcmp(av[ac], env->fract[i]) == 0)
			return (0);
	}
	ft_usage(env);
	return(1);
}

void	ft_usage(t_env *env)
{
	int	i;

	i = -1;
	ft_putstr("Fractals Available :\n");
	while (++i < env->nbfract)
	{
		ft_putstr("   |\n");
		ft_putstr("   |-->");
		ft_putstr(env->fract[i]);
		ft_putchar('\n');
	}
	exit(0);
}

void	ft_error(int ac, char **av, t_env *env)
{

	if (ac == 1 || ac > 3)
	{
		ft_usage(env);
	}
	else if (ac == 2)
	{
		ft_check_exist(1, av, env);
		if (!(env->fp = malloc(sizeof(t_win))))
			return ;
		env->fp->name = av[1];
	}
	else if (ac == 3)
	{
		ft_check_exist(1, av, env);
		ft_check_exist(2, av, env);
		env->ds = 1;
		if (!(env->fp = malloc(sizeof(t_win))))
			return ;
		env->fp->name = av[1];
		if (!(env->sp = malloc(sizeof(t_win))))
			return ;
		env->sp->name = av[2];
	}
}