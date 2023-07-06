/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:12:54 by sanferna          #+#    #+#             */
/*   Updated: 2023/07/06 12:59:16 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	const char		*p;
	unsigned char	car;

	i = 0;
	car = c;
	len = 0;
	while (s[len] != '\0')
		len++;
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

ssize_t	identify_buffer(char *buffer)
{
	char	*dir;

	dir = ft_strchr(buffer, '\n');
	if (dir != NULL)
		return ((void) printf("El buffer:%s\n tiene salto de linea\n", buffer), dir - buffer + 1);
	dir = ft_strchr(buffer, 0x0A);
	if (dir != NULL)
		return ((void) printf("El buffer:%s\n tiene final de archivo\n", buffer), dir - buffer);
	return ((void) printf("Buffer:%s\nsin nada\n", buffer), -1);
}

void	do_things_buffer(char **dest, char *buff, int fd)
{
	ssize_t	chars_taken;
	ssize_t	i;

	if (buff[0] == 0x0A)
	{
		buff[0] = '\0';
		return ;
	}
	chars_taken = identify_buffer(buff);
	i = chars_taken;
	if (chars_taken >= 0)
	{
		ft_alloc_plus(dest, chars_taken, buff);
		for(int i = chars_taken; i < BUFFER_SIZE + 1; i++)
			buff[i - chars_taken] = buff[i];
		/*while (i <= BUFFER_SIZE + 1)
			buff[i - chars_taken] = buff[i++];*/
		return ;
	}
	else
	{
		ft_alloc_plus(dest, BUFFER_SIZE, buff);
		if (read(fd, buff, BUFFER_SIZE) < 0)
			return (free(*dest));
		return (do_things_buffer(dest, buff, fd));
	}
}

void	ft_alloc_plus(char **dest, ssize_t chars_taken, char *buffer)
{
	char	*new;
	ssize_t	old_size;
	ssize_t	i;

	if(*dest != NULL){
		old_size = 0;
		i = 0;
		while(*dest[old_size] != '\0')
			old_size++;
		new = malloc((old_size + chars_taken + 1) * sizeof(char));

		while(i < old_size)
		{
			new[i] = *dest[i];
			i++;
		}
		while(i < (old_size + chars_taken + 1))
		{
			new[i] = buffer[i - old_size];
			i++;
		}
		free(*dest);
		*dest = new;
	} else {
		i = 0;
		new = malloc(chars_taken);
		while(i < chars_taken + 1)
		{
			new[i] = buffer[i];
			i++;
		}
		*dest = new;
	}
	new[i] = '\0';
}
