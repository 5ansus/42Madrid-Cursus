# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 13:31:12 by sanferna          #+#    #+#              #
#    Updated: 2024/08/13 20:51:32 by sanferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = bst_extend.c push_swap.c utils.c parse.c #tester_bst.c
LIB = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ./libft/

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all fclean clean re

clean:
	rm -rfd $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -rfd $(NAME)
	make -C ./libft/ fclean

re: fclean $(NAME)

test: $(LIB)
	$(CC) $(CFLAGS) -c llist.c
	$(CC) $(CFLAGS) -c llst_tester.c
	$(CC) $(CFLAGS) -o llst_tester llst_tester.o llist.o $(LIB)
	valgrind --leak-check=full ./llst_tester