/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 08:45:50 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 08:02:58 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	env;

	env.ptr = mlx_init();
	if (ac == 1 || ac > 3)
        ft_usage();
	if (ac == 2)
		ft_check_arg(av, ac - 1, &env);
	if (ac == 3)
		ft_check_arg(av, ac - 1, &env);
    ft_mlx_keys(&env);
	return (0);
}