# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 18:53:49 by mthiry            #+#    #+#              #
#    Updated: 2022/02/24 19:01:58 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 15:54:17 by mthiry            #+#    #+#              #
#    Updated: 2022/02/24 18:44:53 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCS =  src/ft_c_displaying.c \
		src/ft_s_displaying.c \
		src/ft_p_displaying.c \
		src/ft_d_and_i_displaying.c \
		src/ft_u_displaying.c \
		src/ft_x_displaying.c \
		src/ft_x_up_displaying.c \
		src/ft_percent_displaying.c \
		src/ft_check_next_char.c \
		src/ft_check_format.c \
		src/ft_printf.c \

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $? -o $(?:.c=.o)

all: $(NAME)

$(LIBFT) :
	make -C libft/
	cp $(LIBFT) $(NAME)

$(NAME)($(OBJS)): $(LIBFT) $(OBJS) 
	ar rcs $(NAME) $%

$(NAME): $(NAME)($(OBJS))

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
