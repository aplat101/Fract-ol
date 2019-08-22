/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/16 03:12:14 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 14:57:45 by aplat       ###    #+. /#+    ###.fr     */
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
	pthread_t	t[5];
	int			zoom;
	double		projx;
	double		projy;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			iter;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		imagex;
	double		imagey;
	double		lx;
	double		ly;
	int			it;
}				t_win;

typedef struct	s_env
{
	void		*ptr;
	int			ds;
	t_win		*fp;
	t_win		*sp;
}				t_env;

int     ft_check_exist(int ac, char **av);
void	ft_usage();
void	ft_check_arg(char **av, int ac, t_env *env);
void	ft_alloc_win(int ac, t_env *env);


void	ft_start_julia(t_win *w);

void	ft_start_fract(t_win *w);

void	ft_reset_img(t_win *w);

void	ft_create_window(t_win *w);

void	*julia(void *arg);

void	ft_start_mandelbrot(t_win *w);
void	*mandelbrot(void *arg);

void	ft_start_ship(t_win *w);
void	*ship(void *arg);

void	ft_init_fract(t_env *env);
void	ft_mlx_keys(t_env *env);
int		close_cross(t_env *env);
void	ft_new_img(t_win *w);

//int		ft_check_exist(int ac, char **av, t_env *env);
//void	ft_usage();
void	ft_error(int ac, char **av, t_env *env);

//void    ft_create_window(t_env *env);
void	ft_create_info(t_win *win, t_env *env);
void	ft_frame(t_win *win);

int		key_press_w1(int keycode, t_env *env);
int		key_release_w1(int keycode, t_env *env);
int		mouse_press_w1(int button, int x, int y, t_env *env);

int		key_press_w2(int keycode, t_env *env);
int		key_release_w2(int keycode, t_env *env);
int		mouse_press_w2(int button, int x, int y, t_env *env);

void	ft_reset_values(t_win *w);
void	ft_init_switch(t_env *env);
void	ft_init_fract_values(t_win *w);
//void	ft_start_fract(t_win *w);

void	ft_refresh_mandel_values(t_win *w);
void	ft_mandelbrot(t_win *w);

void	ft_refresh_julia_values(t_win *w);
void	ft_julia(t_win *w);

void	ft_move_right(t_win *w);
void	ft_move_left(t_win *w);
void	ft_move_down(t_win *w);
void	ft_move_up(t_win *w);

void	ft_center(t_win *w);
int		ft_in_img(t_win *w);
void	ft_iterp(t_win *w);
void	ft_iterm(t_win *w);

void	ft_ship(t_win *w);

void	ft_zoomp(t_win *w);
void	ft_zoomm(t_win *w);

#endif
