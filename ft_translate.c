/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_translate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 06:30:19 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 14:59:49 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_right(t_win *w)
{
	w->projx += 10;
	ft_start_fract(w);
}

void	ft_move_left(t_win *w)
{
	w->projx -= 10;
	ft_start_fract(w);
}

void	ft_move_down(t_win *w)
{
	w->projy += 10;
	ft_start_fract(w);
}

void	ft_move_up(t_win *w)
{
	w->projy -= 10;
	ft_start_fract(w);
}