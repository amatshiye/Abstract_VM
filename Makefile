# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 07:33:09 by amatshiy          #+#    #+#              #
#    Updated: 2018/06/26 14:36:40 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = main.cpp src/FileEngine.cpp src/ErrorEngine.cpp

OBJ = bin/main.o bin/FileEngine.o bin/ErrorEngine.o

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
