CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_calloc.c \
	ft_putstr_fd.c
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
