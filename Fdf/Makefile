# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 12:17:50 by mthiry            #+#    #+#              #
#    Updated: 2022/05/12 17:34:22 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c \
		error.c \
		free.c \
		get_args_map.c \
		init_map.c \
		init_map_utils.c \
		init_mlx.c \
		env_mlx.c \
		draw_all.c \
		bresenham.c \
		hook.c \
		draw_utils.c \
		exit_fdf.c \
		
OBJS = $(SRCS:.c=.o)

%.o : %.c
	@tput setaf 32 && echo [Making Objects]
	@tput setaf 34
	$(CC) $(CFLAGS) -c $? -o $(?:.c=.o)
	@tput setaf 32 && echo [Objects Done]

all: $(NAME)

$(LIBFT):
	@tput setaf 32 && echo [Making Libft]
	@tput setaf 34
	@$(MAKE) -C libft/ $(MAKECMDGOAL)
	@tput setaf 32 && echo [Libft Compiled]
	@echo ---------------------------------

$(MLX):
	@tput setaf 32 && echo [Making MLX]
	@tput setaf 34
	@make -C mlx/
	@tput setaf 32 && echo [MLX Compiled]
	@echo ---------------------------------

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@tput setaf 32 && echo [Making Executable]
	@tput setaf 34
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $@ $^
	@tput setaf 32 && echo [Executable Compiled]
	@echo ---------------------------------

clean:
	@tput setaf 35
	@make clean -C libft/
	@make clean -C mlx/
	rm -f $(OBJS)
	@tput setaf 31 && echo Deleted Objects from Libft and from root!
	@echo ---------------------------------

fclean: clean
	@tput setaf 35
	rm -rf $(LIBFT)
	rm -rf $(MLX) 
	rm -rf $(NAME)
	@tput setaf 31 && echo Deleted Executable and Libft!
	@echo ---------------------------------

re: fclean all

.PHONY: all clean fclean re
