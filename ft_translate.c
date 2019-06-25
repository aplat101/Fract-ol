/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_translate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 14:17:31 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 15:01:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_right(t_win *w)
{
	w->projx += 20;
	ft_start_fract(w);
}

void	ft_move_left(t_win *w)
{
	w->projx -= 20;
	ft_start_fract(w);
}

void	ft_move_down(t_win *w)
{
	w->projy += 20;
	ft_start_fract(w);
}

void	ft_move_up(t_win *w)
{
	w->projy -= 20;
	ft_start_fract(w);
}