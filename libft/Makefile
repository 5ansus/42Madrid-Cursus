CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_strlen.c \
	  ft_memset.c \
	  ft_isalpha.c \
	  ft_putstr_fd.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c #$(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

libft.a: $(OBJ)
	ar rc -s libft.a $^

re: fclean $(NAME) 

.PHONY: all fclean clean re
clean:
	rm -rfd $(OBJ)
fclean: clean
	rm -rfd $(NAME)
