all: libft.a

ft_strlen.o: ft_strlen.c
	gcc -Wall -Wextra -Werror -c ft_strlen.c

ft_menset.o: ft_memset.c
	gcc -Wall -Wextra -Werror -c ft_memset.c
libft.a: ft_strlen.o ft_memset.o
	ar rc -s libft.a ft_strlen.o ft_memset.o
