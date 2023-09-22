#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
void	staticFunt(char *punt){

	for(size_t i = 5; i <= strlen(punt); i++){
		punt[i-5] = punt[i];
	}

}

int main(){
	int fd = open("vacio.txt", O_RDONLY);
	char *pointer;
	for(int i = 0; i < 2; i++){
		pointer = get_next_line(fd);
		if(pointer != NULL){
			printf("He leido:\n%s\n", pointer);
			printf("Free desde el main\n");
			free(pointer);
		}
		else{
			printf("Error");
		}
	}
	close(fd);
}
