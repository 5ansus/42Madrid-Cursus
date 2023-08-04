/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:12:54 by sanferna          #+#    #+#             */
/*   Updated: 2023/08/04 19:10:51 by sanferna         ###   ########.fr       */
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
	return dir - buffer + 1;
		//return ((void) printf("El buffer:%s\n tiene salto de linea\n", buffer), dir - buffer + 1);
	dir = ft_strchr(buffer, 0x0A);
	if (dir != NULL)
		//return ((void) printf("El buffer:%s\n tiene final de archivo\n", buffer), dir - buffer);
		return dir-buffer;
	//return ((void) printf("Buffer:%s\nsin nada\n", buffer), -1);
	return -1;
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
	printf("El buffer es %s\n y tiene salto de l'inea en %ld\n", buff, chars_taken);
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
		printf("Hay malloc previo. Malloc\n");
		old_size = 0;
		i = 0;
		printf("Habia escrito %s\n", *dest);
		while((*dest)[old_size] != '\0'){
			//write(0, *dest[old_size], 1);
			//write(0, "\n", 1);
			old_size++;
			printf("Old size = %ld -- chars_taken = %ld\n", old_size, chars_taken);
			printf("Quiero malloc de %ld\n", old_size + chars_taken);
		}
		/*while(*dest[old_size] != '\0')
			old_size++;*/

		printf("Quiero malloc de %ld\n", old_size + chars_taken + 1);
		fflush(stdout);
		new = malloc((old_size + chars_taken + 1) * sizeof(char));
		write(0, "Malloc correcto\n", sizeof("Malloc correcto\n"));
		while(i < old_size)
		{
			new[i] = (*dest)[i];
			i++;
		}
		while(i < (old_size + chars_taken))
		{
			new[i] = buffer[i - old_size];
			i++;
		}
		printf("Free del malloc previo\n");
		free(*dest);
		*dest = new;
	} else {
		i = 0;
		new = malloc(chars_taken);
		printf("No hay malloc previo. Malloc\n");
		while(i < chars_taken)
		{
			new[i] = buffer[i];
			i++;
		}
		*dest = new;
		printf("He escrito %s\n", new);
	}
	new[i] = '\0';
}
