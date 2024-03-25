CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = server client
SRC = server.c client.c
LIB = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ./libft/

server: $(OBJ:client.o= ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $@.o $(LIB)

client: $(OBJ:server.o= ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $@.o $(LIB)

.PHONY: all fclean clean re

clean:
	rm -rfd $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -rfd $(NAME)
	make -C ./libft/ fclean

re: fclean $(NAME)
