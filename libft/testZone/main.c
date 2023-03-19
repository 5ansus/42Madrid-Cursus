#include <string.h>
#include <stdio.h>
void pruebasNull(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("------------------------------------------------");
	printf("Test 2: NULL - NULL N = 0\nRet: %d\n%s\n", strncmp(NULL, NULL, 0), string); // reltado 0
	printf("------------------------------------------------");
	printf("Test 3: NULL - NULL N < 0\nRet: %d\n%s\n", strncmp(NULL, NULL, -1), string);
	printf("------------------------------------------------");
	printf("Test 1: NULL - NULL N > 0\nRet: %d\n%s\n", strncmp(NULL, NULL, 80), string);
}


void pruebasStrNull(){
	char string[100] = "Hola ";
	char string2[] = "mundo";
	printf("Test 2: String - NULL N = 0\nRet: %d\n%s\n", strncmp(string, NULL, 0), string);
	printf("------------------------------------------------");
    printf("Test 1: String - NULL N > 0\nRet: %d\n%s\n", strncmp(string, NULL, 80), string);
	printf("------------------------------------------------");
	printf("Test 3: String - NULL N < 0\nRet: %d\n%s\n", strncmp(string, NULL, -1), string);
	printf("------------------------------------------------");
}
int main()
{
	pruebasStrNull();
}
