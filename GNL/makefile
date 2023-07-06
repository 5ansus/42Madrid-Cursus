all: prueba

prueba: main.o get_next_line.o get_next_line_utils.o
	gcc $^
%.o: %.c
	gcc -Wall -Wextra -o $@ -c $<
