CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = tester
SRC = bst_extend.c tester_bst.c
LIB = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ./libft/

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all fclean clean re cleanlib

clean:
	rm -rfd $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -rfd $(NAME)
	make -C ./libft/ fclean

re: fclean $(NAME)

cleanlib:
	rm -f ./libft/libft.a
