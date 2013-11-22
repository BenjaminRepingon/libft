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

FT_C=ft_isascii.c ft_memchr.c ft_putstr.c ft_strdup.c ft_strncpy.c ft_isdigit.c	\
	ft_memcmp.c ft_strcat.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_islower.c	\
	ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_isprint.c	\
	ft_memmove.c ft_strcmp.c ft_strlen.c ft_strstr.c ft_isalnum.c ft_isupper.c	\
	ft_memset.c ft_strncat.c ft_tolower.c ft_isalpha.c ft_memccpy.c ft_putchar.c\
	ft_strcpy.c ft_strncmp.c ft_toupper.c ft_strtol.c

FT_O=$(FT_C:.c=.o)

all: $(NAME)

$(NAME): lib

o:
	mv main.c main
	gcc -c $(CFLAGS) $(FT_C) $(NAME).h
	mv main main.c

lib: o
	ar r $(NAME).a $(FT_O)
	cp libft.a ./lib/libft.a
	cp libft.h ./include/libft.h

clean:
	rm -rf $(FT_O)

fclean: clean

re: fclean all

test: re
	gcc -I include -L lib -O main.c -o main -lft
	./main

test2: re
	gcc -I include -L lib -O main2.c -o main2 -lft
	./main2