# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/05 14:20:07 by dchirol           #+#    #+#              #
#    Updated: 2017/05/31 12:09:06 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG= false

NAME = ft_ls

SRC =	src/ft_ls.c src/main.c	src/utilities.c	src/sorting.c 	\
		src/sorting_folder.c	src/writebuf.c	src/display.c 	\
		src/display_spe.c		src/flag.c 		src/init.c 		\
		src/sorting_double.c 	src/utilities_2.c 				\
		src/writebuf_2.c 		src/writebuf_3.c 				\
		src/ft_opendir.c 		src/ft_put_ls.c 				\
		src/others.c

CC = gcc

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

ifeq ($(DEBUG), true)
	CFLAGS = -I includes -g
else
	CFLAGS = -Wall -Wextra -Werror -I includes
endif
OBJ = $(SRC:.c=.o)

all : lib $(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(LIB)

lib:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re : clean all
