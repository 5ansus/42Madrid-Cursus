#make $LIB
gcc -c numeric_utils.c
gcc main.c numeric_utils.o libft/libft.a
