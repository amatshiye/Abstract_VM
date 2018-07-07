# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 07:33:09 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/07 07:08:08 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = main.cpp src/FileEngine.cpp src/ErrorEngine.cpp src/ErrorDetails.cpp \
	src/StackEngine.cpp

OBJ = bin/main.o bin/FileEngine.o bin/ErrorEngine.o bin/ErrorDetails.o \
	bin/StackEngine.o

CMP = clang++

FLAGS = -Wall -Werror -Wextra -std=c++11

test: re
	clear && ./avm test.avm

all: to_obj
	$(CMP) -o $(NAME) $(OBJ) $(FLAGS)

to_obj:
	$(CMP) -c $(SRC) $(FLAGS)
	@mv *.o bin/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
