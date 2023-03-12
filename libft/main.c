#include <stdio.h>
#include "libft.h"
int main()
{
	char string[100];
	ft_memset(string, 'A', 99);
	string[99] = 0;
	//printf("La cadena 'Hola Mundo' tiene %d caracteres\n", ft_strlen("Hola mundo"));
	printf("Cadena\n %s \n", string);
}
