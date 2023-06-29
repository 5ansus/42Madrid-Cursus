/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:13:10 by sanferna          #+#    #+#             */
/*   Updated: 2023/06/29 15:22:46 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

char	*get_next_line(int fd){

	static char	buffer[BUFFER_SIZE + 1];
	ssize_t	chars_read;
	char *ret;

	if(identifyBuffer(buffer) == NORMAL_BUFFER){

	}
	/*if(buffer[0] == '\0')
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0) return READ_CHASH;
		buffer[chars_read] = '\0';
	}*/

}



int identifyBuffer(char *buffer)
{
	if (ft_strchr(buffer, '\n') != NULL) return BUFFER_WITH_BREAK;
	if (ft_strchr(buffer, 0x0A) != NULL) return END_OF_FILE;
	return NORMAL_BUFFER;
}

/*int main(){
	//get_next_line();

	//ssize_t		n_chars_read;
	char		*ret;
	//char		*end_line;

	ret = NULL;
	/printf("Hola %lu", strlen(buffer));
	strlcat(buffer, "Hola01234567890123456789012345789012345678901234567890123456789", 50);
	printf("Hola %lu", strlen(buffer));/
	int fd = open("vacio.txt", O_RDONLY);
	printf("%zd -- %s\n", read(fd, buffer, BUFFER_SIZE), buffer);

	printf("%zd -- %s\n", read(fd, buffer, BUFFER_SIZE), buffer);
	printf("%p -- %p\n", buffer, ft_strchr(buffer, 0));
	close(fd);
	return NULL;
}*/
