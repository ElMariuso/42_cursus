# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 12:17:50 by mthiry            #+#    #+#              #
#    Updated: 2022/05/04 17:05:47 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCM = 	main.c \

SRCS =	init_stacks.c \
		swap_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \
		push_operations.c \
		sort.c \
		check_stack.c \
		free.c \
		errors.c \
		utils.c	\
		bools.c \
		simplification.c \
		short_sort.c \

SRCB = 	main_bonus.c \
		instructions_bonus.c \
		
OBJM = $(SRCM:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

%.o : %.c
	@tput setaf 32 && echo [Making Objects]
	@tput setaf 34
	$(CC) $(CFLAGS) -c $? -o $(?:.c=.o)
	@tput setaf 32 && echo [Objects Done]

all: $(NAME)
bonus: $(BONUS)

$(LIBFT):
	@tput setaf 32 && echo [Making Libft]
	@tput setaf 34
	@$(MAKE) -C libft/ $(MAKECMDGOAL)
	@tput setaf 32 && echo [Libft Compiled]
	@echo ---------------------------------

$(NAME): $(OBJM) $(OBJS) $(LIBFT)
	@tput setaf 32 && echo [Making Executable]
	@tput setaf 34
	$(CC) $(CFLAGS) -o $@ $^
	@tput setaf 32 && echo [Executable Compiled]
	@echo ---------------------------------

$(BONUS): $(OBJB) $(OBJS) $(LIBFT)
	@tput setaf 32 && echo [Making Executable]
	@tput setaf 34
	$(CC) $(CFLAGS) -o $@ $^
	@tput setaf 32 && echo [Executable Compiled]
	@echo ---------------------------------

clean:
	@tput setaf 35
	@make clean -C libft/
	rm -f $(OBJM) $(OBJS) $(OBJB) 
	@tput setaf 31 && echo Deleted Objects from Libft and from root!
	@echo ---------------------------------

fclean: clean
	@tput setaf 35
	rm -rf $(LIBFT) 
	rm -rf $(NAME) $(BONUS)
	@tput setaf 31 && echo Deleted Executable and Libft!
	@echo ---------------------------------

re: fclean all

.PHONY: all clean fclean re
