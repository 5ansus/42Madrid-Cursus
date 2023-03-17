#include <stdio.h>
#include <string.h>
#include "../libft.h"
int main()
{
	char string[100] = "Hola ";
	char string2[] = "mundo";
	char string3[100] = "Hola ";
	char string4[] = "mundo";
	printf("%zu\n", strlcat(string, NULL, 10));
	//printf("%zu\n", ft_strlcat(string3, string4, 1));
	printf("Cadena\n%s\n", string);
	printf("Cadena 2\n%s\n", string3);
}
