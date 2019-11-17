/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_zoomiter.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 17:43:34 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 19:36:18 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_iterm(t_win *w)
{
	if (w->iter_max - 2 <= 10)
		w->iter_max = 10;
	else
		w->iter_max -= 2;
	ft_start_fract(w);
}

void	ft_iterp(t_win *w)
{
	w->iter_max += 2;
	ft_start_fract(w);
}

void	ft_zoomp(t_win *w, int x, int y)
{
	if (w->zoom * 1.3 > 100000)
	{
		w->zoom = 100000;
		return ;
	}
	w->x1 = ((double)x / w->zoom + w->x1) - (x / (w->zoom * 1.3));
	w->y1 = ((double)y / w->zoom + w->y1) - (y / (w->zoom * 1.3));
	w->x2 = ((double)x / w->zoom + w->x2) - (x / (w->zoom * 1.3));
	w->y2 = ((double)y / w->zoom + w->y2) - (y / (w->zoom * 1.3));
	w->zoom *= 1.3;
	w->iter_max++;
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
	if (w->iter_max - 1 <= 10)
		w->iter_max = 10;
	else
		w->iter_max--;
	ft_reset_img(w);
	ft_start_fract(w);
}
