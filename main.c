/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:07:24 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 16:09:47 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_env	env;

	ft_init_fract(&env);
	ft_error(ac, av, &env);
	ft_create_window(&env);
	ft_init_switch(&env);
	ft_mlx_keys(&env);
	return (0);
}