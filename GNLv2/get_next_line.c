/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:03:47 by sanferna          #+#    #+#             */
/*   Updated: 2023/09/29 14:35:37 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char *dir;

	//ssize_t		chars_read;
	char		*ret;

	ret = NULL;
	if (analyse_buffer(buffer) == EMPTY_BUFFER){
		read(fd, buffer, BUFFER_SIZE);
	if(analyse_buffer(buffer) != BR_BUFFER)
	{
		//expandir buffer
	}

	dir = ft_strchr(buffer, '\n');
	ret = malloc(dir - buffer + 2); //malloc del número de caracteres encontrados + 2 (/n /0)
	ft_memmove(ret, buffer, dir - ret + 1); //Copiar incluyendo el /n que hemos encontradp. Falta añadir el /0 al ret
	ft_memmove(buffer, dir + 1, BUFFER_SIZE - (dir - buffer)); //actualizar buffer copiando el /0 del final
	return (ret);
}
