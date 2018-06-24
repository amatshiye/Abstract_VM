# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 07:33:09 by amatshiy          #+#    #+#              #
#    Updated: 2018/06/24 12:26:31 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = main.cpp src/FileEngine.cpp #Operand.cpp

OBJ = bin/main.o bin/FileEngine.o

CMP = clang++

FLAGS = -Wall -Werror -Wextra -std=c++11

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
