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
	printf("He leido:\n%sFIN\n", get_next_line(fd));
	printf("He leido:\n%sFIN\n", get_next_line(fd));
	close(fd);
}
