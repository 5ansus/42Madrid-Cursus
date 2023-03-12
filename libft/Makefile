CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_strlen.c \
	  ft_memset.c \
	  ft_isalpha.c \
	  ft_putstr_fd.c \
	  ft_calloc.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c #$(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc -s $@ $^

re: fclean $(NAME) 

.PHONY: all fclean clean re
clean:
	rm -rfd $(OBJ)
fclean: clean
	rm -rfd $(NAME)
