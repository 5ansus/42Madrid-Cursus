# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 17:30:19 by sanferna          #+#    #+#              #
#    Updated: 2025/02/22 17:30:50 by sanferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME =
SRC =
LIB = ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a
OBJ = $(SRC:.c=.o)
gcc main.c -Lminilibx-linux -lmlx -lX11 -lXext
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ./libft/
	make -C ./minilibx_opengl_20191021/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all fclean clean re

clean:
	rm -rfd $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -rfd $(NAME)
	make -C ./libft/ fclean

re: fclean $(NAME)
