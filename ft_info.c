/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_info.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 14:31:12 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 19:25:22 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_info(t_win *w)
{
	int	bpp;
	int	s_l;
	int	endian;
	int	x;
	int	y;

	w->info_ptr = mlx_new_image(w->ptr, INFO, HH);
	w->info = (int*)mlx_get_data_addr(w->info_ptr, &(bpp), &(s_l), &(endian));
	y = (HH * 0.69) - 1;
	while (++y < HH * 0.97)
	{
		x = (INFO / 2) - 1;
		while (++x < INFO - 20)
			w->info[(int)((y * INFO) + x)] =
			w->inf->c[(int)((y / (HH * 0.04) - (0.69 / 0.04)))];
	}
	mlx_put_image_to_window(w->info, w->win, w->info_ptr, POST, 0);
	ft_fill_info(w);
}

void	ft_fill_info(t_win *w)
{
	int	cent;

	cent = POST + ((WD - POST) * 0.3);
	ft_take_info(w);
	mlx_string_put(w->ptr, w->win, cent, HH * 0.02, w->fc, "Fractol");
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.07, w->fc, w->inf->name);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.11, w->fc, w->inf->iter);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.15, w->fc, w->inf->zoom);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.19, w->fc, w->inf->color);
	mlx_string_put(w->ptr, w->win, cent, HH * 0.24, w->fc, "Controls");
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.28, w->fc, ESC);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.32, w->fc, SWAP);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.36, w->fc, ITER);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.40, w->fc, ZP);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.44, w->fc, ZM);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.48, w->fc, RESET);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.52, w->fc, SWAPC);
	mlx_string_put(w->ptr, w->win, POSTP, HH * 0.56, w->fc, VAR);
	if (w->variant == 0)
		mlx_string_put(w->ptr, w->win, POST + 30, HH * 0.60, w->fc, DIS);
	else if (w->variant == 1)
		mlx_string_put(w->ptr, w->win, POST + 30, HH * 0.60, w->fc, ENA);
	mlx_string_put(w->ptr, w->win, cent + 10, HH * 0.65, w->fc, "Colors");
}

void	ft_take_info(t_win *w)
{
	int	i;

	i = -1;
	w->inf->name = ft_strjoin("- Name ==> ", w->name);
	w->inf->iter = ft_strjoin("- Iterations ==> ", ft_itoa(w->iter_max));
	w->inf->zoom = ft_strjoin("- Zoom ==> ", ft_itoa(w->zoom));
	w->inf->color = ft_strjoin("- Mode Color ==> ", ft_itoa(w->c));
	while (++i < 7)
	{
		w->inf->col[i] = ft_strjoin("- ", ft_int_to_hex(w->inf->c[i]));
		mlx_string_put(w->ptr, w->win, POSTP, HH * (0.70 + (i * 0.04)),
		w->inf->c[i], w->inf->col[i]);
	}
}

char		*ft_int_to_hex(int	nb)
{
	int		i;
	char	*res;

	res = ft_strnew(7);
	res[0] = '#';
	i = 7;
	while (--i > 0)
	{
		res[i] = '0';
		if (nb % 16 > 9)
			res[i] = 65 + (nb % 16) - 10;
		else
			res[i] = 48 + (nb % 16);
		nb /= 16;
	}
	res[7] = '\0';
	return (res);
}
