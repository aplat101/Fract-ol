/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 06:13:03 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 19:00:04 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_variant_julia(t_win *w)
{
	int		res;

	res = w->variant;
	if (res == 0)
		w->variant = 1;
	else
		w->variant = 0;
	ft_start_fract(w);
}

void		ft_swap_multi(t_win *w)
{
	int		res;

	res = w->flat;
	if (res == 0)
		w->flat = 1;
	else
		w->flat = 0;
	ft_start_fract(w);
}

void		ft_swap_fract(t_win *w)
{
	int		fract;

	fract = 0;
	if (ft_strcmp(w->name, JULIA) == 0)
		fract = 1;
	if (ft_strcmp(w->name, MANDEL) == 0)
		fract = 2;
	if (ft_strcmp(w->name, SHIP) == 0)
		fract = 3;
	fract == 1 ? w->name = MANDEL : 0;
	fract == 2 ? w->name = SHIP : 0;
	fract == 3 ? w->name = JULIA : 0;
	ft_start_fract(w);
}

void		ft_reset_img(t_win *w)
{
	int		i;
	int		j;

	i = 0;
	while (i < HH)
	{
		j = 0;
		while (j < POST)
		{
			w->img[(int)((i * POST) + j)] = 0;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
	ft_create_info(w);
}
