#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:49:07 by rbenjami          #+#    #+#              #
#    Updated: 2013/11/20 11:31:21 by rbenjami         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC= gcc
CFLAGS= -Werror -Wall -Wextra -ansi -pedantic
NAME=libft

all: $(NAME)

$(NAME): lib

o:
	mv main.c main
	gcc -c $(CFLAGS) *.c *.h
	mv main main.c

lib: o
	ar r $(NAME).a *.o
	mv libft.a ./lib/libft.a
	cp libft.h ./include/libft.h

clean:
	rm -rf *~ *#

fclean: clean
	rm -rf *.o

re: fclean all

test: re
	gcc -I include -L lib -O main.c -o main -lft
	./main