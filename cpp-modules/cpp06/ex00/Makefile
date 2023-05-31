# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 16:10:06 by root              #+#    #+#              #
#    Updated: 2022/10/25 14:14:39 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
SRCS = main.cpp  \
		Convert.cpp
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