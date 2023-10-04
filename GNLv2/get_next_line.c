/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:03:47 by sanferna          #+#    #+#             */
/*   Updated: 2023/10/04 18:13:55 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*ret;

	ret = NULL;
	if ((buffer[0] == 0) && (read(fd, buffer, BUFFER_SIZE) <= 0))
		return NULL;
	if (gnl_rec(&ret, buffer, fd) == GNL_OK)
		return ret;
	return NULL;
}

char	gnl_rec(char **ret, char *buffer, int fd)
{
	ssize_t	chars_read;
	char *break_dir;


	if (buffer[0] == 0)
	{
		chars_read == read(fd, buffer, BUFFER_SIZE);
		buffer[chars_read] = 0;
	}
	if (chars_read < 0)
		return (free(*ret), GNL_ERR);
	if (chars_read < BUFFER_SIZE || analyse_buffer(buffer) == NO_BR_BUFFER)
	{
		buffer[0] = 0;
		return (realloc_plus(ret, buffer, chars_read));
	}
	break_dir = ft_strchr(buffer, '\n');
	if (realloc_plus(ret, buffer, break_dir - buffer + 1) == GNL_ERR)
		return GNL_ERR; // +1 porque tiene que contar el /n. REALLOC PLUS TIENE QUE METER EL /0
	ft_memmove(buffer, break_dir + 1, BUFFER_SIZE - (break_dir - buffer + 1) + 1); //Quito los caracteres leidos y copio el /0
	return GNL_OK;
	/*
	Hacer Caso de que encuentra /n o caso de que no encuentra /n, es decir, llamar otra vez a la funci'on
	*/
}

int main(){
	(void) get_next_line(0);
}
