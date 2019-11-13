# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/19 16:37:18 by aplat        #+#   ##    ##    #+#        #
#    Updated: 2019/11/13 19:55:28 by aplat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

SRC = main.c ft_error.c ft_init_fract.c ft_utils.c ft_julia.c \
		ft_bind_keys_fp.c ft_bind_keys_sp.c ft_info.c ft_mandelbrot.c\
		ft_ship.c ft_mlx.c ft_zoomiter.c ft_color.c

CC = gcc

DEPENDENCES = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

HEADERS = fractol.h
INFO = info.h

LIB = libft/libft.a 

LIBX = minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

$(NAME) : $(LIB) $(LIBX) $(DEPENDENCES) $(HEADERS) $(INFO)
	@$(CC) $(CFLAGS) -lpthread -o $(NAME) $(SRC) -L./libft -lft $(LIBX) $(FRAMEWORK) -I $(HEADERS) -I $(INFO)
	@echo "\033[32mCompilation ==> DONE\033[0m"

$(LIB) :
	@make -C libft

$(LIBX) :
	@make -C minilibx_macos

all : $(NAME)

clean:
	@rm -f $(DEPENDENCES)
	@make clean -C libft
	@make clean -C minilibx_macos
	@echo "\033[32mSuppression .o ==> DONE\033[0m"

fclean:clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\033[32mSuppression binaires ==> DONE"

re:fclean $(NAME)

.PHONY: all clean fclean re

.SILENT: $(DEPENDENCES)
