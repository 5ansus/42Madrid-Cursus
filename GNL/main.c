#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	staticFunt(char *punt){

	for(int i = 5; i <= strlen(punt); i++){
		punt[i-5] = punt[i];
	}

}

int main(){
	static char	buffer[50 + 1];
	strcpy(buffer, "Hola Mundo!");
	printf("%s\n", buffer);
	staticFunt(buffer);
	printf("%s\n", buffer);

}
