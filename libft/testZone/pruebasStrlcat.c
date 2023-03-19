#include <stdio.h>
#include <string.h>
#include "../libft.h"

void pruebasNull(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("Test 1: NULL - NULL N > 0\nSize: %zu\n%s\n", strlcat(NULL, NULL, 80), string);
	printf("------------------------------------------------");
	printf("Test 2: NULL - NULL N = 0\nSize: %zu\n%s\n", strlcat(NULL, NULL, 0), string);
	printf("------------------------------------------------");
	printf("Test 3: NULL - NULL N < 0\nSize: %zu\n%s\n", strlcat(NULL, NULL, -1), string);
	printf("------------------------------------------------");
}

void pruebasPlusNull(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("Test 1: string - NULL N > 0\nSize: %zu\n%s\n", strlcat(string, NULL, 80), string);
	printf("------------------------------------------------\n");

	strcpy(string, string2);
	printf("Test 2: string - NULL N = 0\nSize: %zu\n%s\n", strlcat(string, NULL, 0), string);
	printf("------------------------------------------------\n");

	strcpy(string, string2);
	printf("Test 3: string - NULL N < 0\nSize: %zu\n%s\n", strlcat(string, NULL, -1), string);
	printf("------------------------------------------------");
}

void pruebasNull2(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("Test 1: string - NULL N > 0\nSize: %zu\n%s\n", strlcat(NULL, string2, 80), string);
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	printf("Test 2: string - NULL N = 0\nSize: %zu\n%s\n", strlcat(NULL, string2, 0), string);
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	printf("Test 3: string - NULL N < 0\nSize: %zu\n%s\n", strlcat(NULL, string2, -1), string);
	printf("------------------------------------------------");
}

void pruebas(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("Test 1: string - NULL N = 80\nSize: %zu\n%s\n", strlcat(string, string2, 80), string);
	strcpy(string,  "Hola ");
	printf("Your result test 1: string - NULL N = 80\nSize: %zu\n%s\n", ft_strlcat(string, string2, 80), string);
	printf("------------------------------------------------\n");
	printf("------------------------------------------------\n");

	for (int i = 0; i <= 12; i++){
		strcpy(string,  "Hola ");
		printf("Test %d: string - NULL N = %d\nSize: %zu\n%s\n", i + 2, i, strlcat(string, string2, i), string);
		//printf("------------------------------------------------\n");
		strcpy(string,  "Hola ");
		printf("Your result test %d: string - NULL N = %d\nSize: %zu\n%s\n", i + 2, i, ft_strlcat(string, string2, i), string);
		printf("------------------------------------------------\n");
	}

	/*strcpy(string,  "Hola ");
	printf("Test 2: string - NULL N = 2\nSize: %zu\n%s\n", strlcat(string, string2, 2), string);
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	printf("Test 3: string - NULL N = 3\nSize: %zu\n%s\n", strlcat(string, string2, 3), string);
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	printf("Test 4: string - string N = 9\nSize: %zu\n%s\n", strlcat(string, string2, 9), string);
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	printf("Test 4: string - string N = 11\nSize: %zu\n%s\n", strlcat(string, string2, 11), string);*/
	printf("------------------------------------------------\n");

	strcpy(string,  "Hola ");
	//printf("Test 15: string - NULL N < 0\nSize: %zu\n%s\n", strlcat(string, string2, -1), string);
	printf("------------------------------------------------");
}

int main()
{
	pruebas();
}
