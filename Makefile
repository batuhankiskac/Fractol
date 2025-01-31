# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 17:58:52 by bkiskac           #+#    #+#              #
#    Updated: 2025/01/30 21:53:01 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -g
MLXFLAGS = -lm -lX11 -lXext

SRCS = fractol.c \
	src/fractol_color.c \
	src/fractol_events.c \
	src/fractol_init.c \
	src/fractol_render.c \
	src/fractol_utils_1.c \
	src/fractol_utils_2.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C mlx

re: fclean all

.PHONY: all clean fclean re
