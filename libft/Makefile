CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a 
SRC = ft_strlen.c \
	  ft_memset.c 

OBJ = $(SRC:c.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft.a: $(OBJ)
	ar rc -s libft.a $^

re: fclean $(NAME) 

.PHONY: fclean
clean:
	rm -rdf $(OBJ)
fclean: clean
	rm -rdf $(NAME)
