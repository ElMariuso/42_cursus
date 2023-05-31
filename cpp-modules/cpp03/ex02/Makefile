# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:18:00 by mthiry            #+#    #+#              #
#    Updated: 2022/10/17 22:47:05 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) -c $(CPP_FLAGS) $?

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: fclean clean re all