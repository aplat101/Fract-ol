/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mandelbrot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 16:56:14 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 21:15:08 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_refresh_mandel_values(t_win *w)
{
	w->cr = w->lx / w->zoomx + w->x1;
	w->ci = w->ly / w->zoomy + w->y1;
	w->zr = 0;
	w->zi = 0;
}

void		ft_start_mandelbrot(t_win *w)
{
	int		i;

	ft_reset_img(w);
	w->imagex = (w->x2 - w->x1) * w->zoomx;
	w->imagey = (w->y2 - w->y1) * w->zoomy;
	i = 0;
	while (i < THREAD)
	{
		w->it = i;
		if (pthread_create(&w->t[i], NULL, mandelbrot, w) == -1)
		{
			perror("pthread_create");
			return ;
		}
		pthread_join(w->t[i], NULL);
		i++;
	}
}

void		*mandelbrot(void *arg)
{
	double	tmp;
	int		i;
	t_win	*w;

	w = arg;
	w->lx = (WD / THREAD * w->it);
	while (w->lx < (WD / THREAD * (w->it + 1)) || w->lx < (w->imagex / THREAD * (w->it + 1)))
	{
		w->ly = 0;
		while (w->ly + w->projy < HH)
		{
			ft_refresh_mandel_values(w);
			i = -1;
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 && ++i < w->iter)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = (2 * w->zi * tmp) + w->ci;
			}
			ft_getcolor(w, i);
		}
		w->lx++;
	}
	pthread_exit(0);
}
