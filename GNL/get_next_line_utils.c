/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:12:54 by sanferna          #+#    #+#             */
/*   Updated: 2023/06/29 16:20:35 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	const char		*p;
	unsigned char	car;

	i = 0;
	car = c;
	len = 0;
	while (s[len] != '\0') len++; /*Tener cuidado si hay /0 en el texto*/
	//while (i <= len)
	while (i <= len)
	{
		if ((unsigned char) s[i] == car)
		{
			p = s + i;
			return ((char *)p);
		}
		i++;
	}
	return (NULL);
}

ssize_t identifyBuffer(char *buffer)
{
	char	*dir;

	dir = ft_strchr(buffer, '\n');
	if (dir != NULL) return dir - buffer + 1;
	dir = ft_strchr(buffer, 0x0A);
	if (dir != NULL) return dir - buffer;
	return -1;
}

void doThingsBuffer(char **dest, char *buff, int fd){
	ssize_t chars_taken;
	//Archivo terminado
	if (buff[0] == 0x0A){
		buff[0] = '\0';
		return;
	}
	//Queda buffer
	chars_taken = identifyBuffer(buff);
	if(chars_taken >= 0){
		ft_alloc_plus(*dest, chars_taken); //solo suma caracteres
		//actualizar buffer moviendo x caracteres
		for(ssize_t i = chars_taken; i <= BUFFER_SIZE + 1; i++){
			buff[i - chars_taken] = buff[i];
		}
		return;
	}else{
		ft_alloc_plus(*dest, BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE) < 0)
		{
			free(*dest);
			return;
		}
		doThingsBuffer(dest, buff, fd);
		return;
	}
}
