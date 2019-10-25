/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 11:26:22 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 15:25:28 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			ft_in_img(int x, int y)
{
	int		res;

	res = 0;
	if (y < HH && y >= 0 && x >= 0 && x < POST)
		res = 1;
	else
		res = 0;
	return (res);
}

void		ft_refresh_julia_values(t_win *w, int x, int y)
{
	w->zr = x / w->zoom + w->x1;
	w->zi = y / w->zoom + w->y1;
}

void		ft_start_julia(t_win *w)
{
	int		i;

	ft_reset_img(w);
	w->cr = w->mouse_x;
	w->ci = w->mouse_y;
	if (w->flat == 1)
		julia_flat(w);
	else
	{
		i = -1;
		while (++i < THREAD)
		{
			w->it = i;
			if (pthread_create(&w->t[i], NULL, julia, w) == -1)
			{
				perror("pthread_create");
				return ;
	    	}
			pthread_join(w->t[i], NULL);
		}
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
}

void		ft_reset_img(t_win *w)
{
	int 	i;
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

void	*julia(void *arg)
{
	double	tmp;
	int		i;
	t_win	*w;
	double	x;
	double	y;
	double	ret;

	w = arg;
	ret = (POST / THREAD * (w->it + 1));
	x = POST / THREAD * w->it - 1;
	while (++x < ret)
	{
		y = -1;
		while (++y < HH)
		{
			ft_refresh_julia_values(w, x, y);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			if (y < HH && y >= 0 && x >= 0 && x < POST)
			{
				if (i == w->iter)
					w->img[(int)((y * POST) + x)] = 0;
				else
					w->img[(int)((y * POST) + x)] = 0x0F100A * i;
			}
		}
	}
	pthread_exit(0);
}

void	julia_flat(t_win *w)
{
	double	tmp;
	int		i;
	double	x;
	double	y;

	x = -1;
	while (++x < POST)
	{
		y = -1;
		while (++y < HH)
		{
			ft_refresh_julia_values(w, x, y);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			if (y < HH && y >= 0 && x >= 0 && x < POST)
			{
				if (i == w->iter)
					w->img[(int)((y * POST) + x)] = 0;
				else
					w->img[(int)((y * POST) + x)] = 0x0F100A * i;
			}
		}
	}
}

/*void	ft_getcolor(t_win *w, int i)
{
	if (i == w->iter && ft_in_img(w) == 1)
		w->img[(int)(((y + w->projy) * POST) + x + w->projx)] = 0;
	else if (ft_in_img(w) == 1)
		w->img[(int)(((y + w->projy) * POST) + x + w->projx)] = 0x0F100A * i;
	y++;
}*/
