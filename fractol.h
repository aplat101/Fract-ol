/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:12:14 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 23:51:29 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "key_map_macos.h"
# include "info.h"
# include <pthread.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_info
{
	char		*name;
	char		*iter;
	char		*zoom;
	char		*color;
	char		*multi;
	int			c[7];
	char		**col;
}				t_info;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_win
{
	void		*ptr;
	void		*win;
	void		*img_ptr;
	int			*img;
	void		*info_ptr;
	int			*info;
	char		*name;
	pthread_t	t[8];
	double		zoom;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			iter_max;
	int			iter;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		mouse_x;
	double		mouse_y;
	int			it;
	int			variant;
	int			flat;
	t_info		*inf;
	t_point		*i;
	double		ret;
	int			c;
}				t_win;


typedef struct	s_env
{
	void		*ptr;
	int			ds;
	t_win		*fp;
	t_win		*sp;
}				t_env;

/*
** Ft_error.c
*/

int     ft_check_exist(int ac, char **av);
void	ft_usage();
void	ft_check_arg(char **av, int ac, t_env *env);
void	ft_alloc_win(int ac, t_env *env);

/*
** Ft_init_fract.c
*/

void	ft_start_fract(t_win *w);
void	ft_reset_values(t_win *w);
void	ft_set_values(t_win *w);

/*
** Ft_zoomiter.c
*/

void	ft_iterp(t_win *w);
void	ft_iterm(t_win *w);
void	ft_zoomp(t_win *w, int x, int y);
void	ft_zoomm(t_win *w, int x, int y);

/*
** Ft_bind_keys_fp.c
*/

int		key_press_w1(int keycode, t_env *env);
int		key_release_w1(int keycode, t_env *env);
int		mouse_press_w1(int button, int x, int y, t_env *env);
int		mouse_move_w1(int x, int y, t_env *env);

/*
** Ft_bind_keys_sp.c
*/

int		key_press_w2(int keycode, t_env *env);
int		key_release_w2(int keycode, t_env *env);
int		mouse_press_w2(int button, int x, int y, t_env *env);
int		mouse_move_w2(int x, int y, t_env *env);

/*
** Ft_mlx.c
*/

void	ft_create_window(t_win *w);
void	ft_mlx_keys(t_env *env);
int		close_cross(t_env *env);

/*
** Ft_info.c
*/

void	ft_create_info(t_win *w);
void	ft_fill_info(t_win *w);
void	ft_take_info(t_win *w);

/*
** Ft_utils.c
*/

void	ft_swap_fract(t_win *w);
void	ft_variant_julia(t_win *w);
void	ft_reset_img(t_win *w);
int		ft_in_img(t_win *w);
void	ft_swap_multi(t_win *w);

/*
** Ft_julia.c
*/

void	ft_start_julia(t_win *w);
void	*julia(void *arg);
void	ft_refresh_julia_values(t_win *w);

/*
** Ft_mandelbrot.c
*/

void	ft_refresh_mandel_values(t_win *w);
void	ft_start_mandelbrot(t_win *w);
void	*mandelbrot(void *arg);

/*
** Ft_ship.c
*/

void	ft_start_ship(t_win *w);
void	*ship(void *arg);

/*
** Ft_color.c
*/

void	ft_swap_color(t_win *w);
int		ft_get_color(t_win *w);
void	ft_take_color(t_win *w, int *color);

void	ft_mandelbrot(t_win *w);
void	ft_init_fract(t_env *env);
void	ft_new_img(t_win *w);
void	ft_error(int ac, char **av, t_env *env);
void	ft_init_switch(t_env *env);
void	ft_init_fract_values(t_win *w);
void	ft_julia(t_win *w);
void	ft_center(t_win *w);
void	ft_ship(t_win *w);
void	julia_flat(t_win *w);

#endif
