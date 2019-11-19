/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ship.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 16:56:42 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 06:08:16 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_start_ship(t_win *w)
{
	int		i;

	i = 0;
	while (i < THREAD)
	{
		w->it = i;
		if (pthread_create(&w->t[i], NULL, &ship, w) == -1)
		{
			perror("pthread_create");
			return ;
		}
		pthread_join(w->t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
	ft_create_info(w);
}

void		*ship(void *arg)
{
	double	tmp;
	t_win	*w;

	w = arg;
	w->i->x = POST / THREAD * w->it - 1;
	while (++(w->i->x) < (POST / THREAD * (w->it + 1)))
	{
		w->i->y = -1;
		while (++(w->i->y) < HH)
		{
			ft_refresh_mandel_values(w);
			while (((w->zr * w->zr) + (w->zi * w->zi)) < 4 &&
				++(w->iter) < w->iter_max)
			{
				tmp = w->zr;
				w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
				w->zi = fabs(2 * w->zi * tmp) + w->ci;
			}
			ft_get_color(w);
		}
	}
	pthread_exit(0);
}
