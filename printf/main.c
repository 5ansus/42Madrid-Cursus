#include "ft_printf.h"
#include <stdio.h>
ssize_t	print_decimal(int num);
ssize_t	print_hex(int num);
ssize_t	print_hex_minus(int num);
ssize_t	print_unsigned(unsigned int num);
ssize_t	print_unsigned_hex(void *p);

int main(){
	print_decimal(-2147483648);
	print_decimal(2147483647);
	print_hex(-2147483648);
	print_hex(2147483647);
	int a = 0xABCD;
	print_hex(a);
	print_hex(-a);
	print_unsigned(-1);
	print_unsigned(4294967295);
	print_unsigned(0);
	int c = 0;
	printf("%p\n", &c);
	print_unsigned_hex((void *) &c);
}
