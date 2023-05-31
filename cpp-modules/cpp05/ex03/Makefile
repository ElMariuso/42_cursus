# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 19:49:45 by root              #+#    #+#              #
#    Updated: 2022/10/22 15:35:16 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Coffee
SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp
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