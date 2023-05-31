# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 22:40:21 by root              #+#    #+#              #
#    Updated: 2022/10/20 20:15:16 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fallout
SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
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