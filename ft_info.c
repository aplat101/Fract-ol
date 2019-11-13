/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_info.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 14:31:12 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 23:00:55 by aplat       ###    #+. /#+    ###.fr     */
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
	mlx_string_put(w->ptr, w->win, POST + ((WD - POST) * 0.3),
	HH * 0.02, 269455, "Fractol");
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.06, 269455, w->inf->name);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.09, 269455, w->inf->iter);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.12, 269455, w->inf->zoom);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.15, 269455, w->inf->color);
	mlx_string_put(w->ptr, w->win, POST + ((WD - POST) * 0.3), HH * 0.19, 269455, "Controls");
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.23, 269455, ESC);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.26, 269455, SWAP);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.29, 269455, ITER);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.32, 269455, ZP);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.35, 269455, ZM);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.38, 269455, RESET);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.41, 269455, SWAPC);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.44, 269455, VAR);
	if (ft_strcmp(w->name, JULIA) == 0 && w->variant == 0)
		mlx_string_put(w->ptr, w->win, POST + 30, HH * 0.47, 269455, DIS);
	else if (ft_strcmp(w->name, JULIA) == 0 && w->variant == 1)
		mlx_string_put(w->ptr, w->win, POST + 30, HH * 0.47, 269455, ENA);
	mlx_string_put(w->ptr, w->win, POST + ((WD - POST) * 0.3), HH * 0.51, 269455, "Colors");
}

void	ft_take_info(t_win *w)
{
	if (!(w->inf = malloc(sizeof(t_info))))
		return ;
	w->inf->name = ft_strjoin("Name ==> ", w->name);
	w->inf->iter = ft_strjoin("Iterations ==> ", ft_itoa(w->iter_max));
	w->inf->zoom = ft_strjoin("Zoom ==> ", ft_itoa(w->zoom));
	w->inf->color = ft_strjoin("Mode Color ==> ", ft_itoa(w->c));
}
