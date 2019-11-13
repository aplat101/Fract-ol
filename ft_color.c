/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 19:37:55 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 23:45:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				ft_get_color(t_win *w)
{
	static int	i[8][7] = {{0xFF0000, 0xF34336, 0xE4605E, 0xD07684, 0xB489AC, 0x899AD5, 0xAAFF},
					{0xFF0000, 0xFF5232, 0xFF7B5A, 0xFF9E81, 0xFFBFAA, 0xFFDFD4, 0xFFFFFF},
					{0x00FF00, 0x7FE757, 0xABCE80, 0xC9B2A2, 0xE091C2, 0xF167E1, 0xFF00FF},
					{0x955628, 0x8F5E41, 0x87665A, 0x7C6E72, 0x6B768A, 0x507EA3, 0x0086BD},
					{0xF0C300, 0xE1C349, 0xCFC46F, 0xBAC490, 0x9EC5B0, 0x75C5D0, 0x00C6F0},
					{0x0F056B, 0x271C5E, 0x302E51, 0x333F44, 0x304F35, 0x256023, 0x007000},
					{0xFF7F00, 0xF18B42, 0xE19669, 0xCBA18F, 0xAFABB4, 0x83B5D9, 0x00BEFF},
					{0xFF0005, 0x1700FF, 0xBEF574, 0xCECECE, 0x512C10, 0x03224C, 0x9EFD38}};

	if (w->i->y < HH && w->i->y >= 0 && w->i->x >= 0 && w->i->x < POST)
	{
		if (w->iter == w->iter_max)
			w->img[(int)((w->i->y * POST) + w->i->x)] = 0;
		else
			w->img[(int)((w->i->y * POST) + w->i->x)] = i[w->c][w->iter % 7];
	}
	return (0);
}

void			ft_swap_color(t_win *w)
{
	if (w->c == 7)
		w->c = 0;
	else
		++(w->c);
	ft_start_fract(w);
}
