/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_info.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 14:31:12 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 22:34:11 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_info(t_win *w)
{
	int	bpp;
	int	s_l;
	int	endian;

	w->info_ptr = mlx_new_image(w->ptr, INFO, HH);
	w->info = (int*)mlx_get_data_addr(w->info_ptr, &(bpp), &(s_l), &(endian));
	ft_fill_info(w);
}

void	ft_fill_info(t_win *w)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HH)
	{
		x = -1;
		while (++x < INFO)
		{
			if ((x >= 0 && x <= 3) || (x < INFO && x >= INFO - 4)
				|| (y >= 0 && y <= 4) || (y < HH && y >= HH - 4))
				w->info[(int)((y * INFO) + x)] = 269455;
		}
	}
	mlx_put_image_to_window(w->info, w->win, w->info_ptr, POST, 0);
	ft_take_info(w);
	mlx_string_put(w->ptr, w->win, POST + ((WD - POST) * 0.40), HH * 0.02, 269455, "Fractol");
	mlx_string_put(w->ptr, w->win, POST + 10, HH * 0.06, 269455, w->inf->name);
	mlx_string_put(w->ptr, w->win, POST + 10, HH * 0.08, 269455, w->inf->iter);
	mlx_string_put(w->ptr, w->win, POST + 10, HH * 0.1, 269455, w->inf->zoom);
}

void	ft_take_info(t_win *w)
{
	if (!(w->inf = malloc(sizeof(t_info))))
		return ;
	w->inf->name = ft_strjoin("Name ==> ", w->name);
	w->inf->iter = ft_strjoin("Iterations ==> ", ft_itoa(w->iter_max));
	w->inf->zoom = ft_strjoin("Zoom ==> ", ft_itoa(w->zoom));
}