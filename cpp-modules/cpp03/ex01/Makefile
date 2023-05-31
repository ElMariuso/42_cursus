# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:18:00 by mthiry            #+#    #+#              #
#    Updated: 2022/10/17 18:47:33 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp
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