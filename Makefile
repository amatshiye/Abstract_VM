# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 07:33:09 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/16 11:56:26 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = main.cpp src/FileEngine.cpp src/ErrorEngine.cpp src/ErrorDetails.cpp \
	src/StackEngine.cpp src/int8.class.cpp src/int16.class.cpp src/int32.class.cpp \
	src/Float.class.cpp src/Double.class.cpp src/CoreEngine.cpp \
	src/CheckFlow.cpp

OBJ = bin/main.o bin/FileEngine.o bin/ErrorEngine.o bin/ErrorDetails.o \
	bin/StackEngine.o bin/int8.class.o bin/int16.class.o bin/int32.class.o \
	bin/Float.class.o bin/Double.class.o bin/CoreEngine.o \
	bin/CheckFlow.o

CMP = clang++

FLAGS = -Wall -Werror -Wextra -std=c++11

#test: re
#	clear && ./avm test.avm

all: to_obj
	$(CMP) -o $(NAME) $(OBJ) $(FLAGS)

to_obj:
	$(CMP) -c $(SRC) $(FLAGS)
	@sh src/create_dir.sh
	@mv *.o bin/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf bin

re: fclean all
