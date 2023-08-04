all: prueba

prueba: main.o get_next_line.o get_next_line_utils.o
	gcc -Wall -Wextra -o get_next_line.o -c get_next_line.c
	gcc -Wall -Wextra -o get_next_line_utils.o -c get_next_line_utils.c
	gcc -Wall -Wextra -o main.o -c main.c
	gcc $^
%.o: %.c
	gcc -Wall -Wextra -o $@ -c $<
