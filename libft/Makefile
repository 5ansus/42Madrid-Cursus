all: libft.a

ft_strlen.o: ft_strlen.c
	gcc -Wall -Wextra -Werror -c ft_strlen.c

libft.a: ft_strlen.o
	ar rc -s libft.a ft_strlen.o
