/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:03:47 by sanferna          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:46 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret;

	ret = NULL;
	if (gnl_rec(&ret, buffer, fd) == GNL_OK)
	{
		//Resuelve muchos problemas uwu
		if (ft_strchr(ret, '\0') == ret)
		{
			free(ret);
			return (NULL);
		}
		return (ret);
	}
	return (NULL);
}

ssize_t	read_upgraded(char *buffer, int fd)
{
	ssize_t	chars_read;

	chars_read = read(fd, buffer, BUFFER_SIZE);
	if (chars_read >= 0)
		buffer[chars_read] = 0;

	return (chars_read);
}

char	gnl_rec(char **ret, char *buffer, int fd)
{
	ssize_t	chars_read;
	char	*br_dir;

	chars_read = ft_strlen(buffer);
	if (buffer[0] == 0)
		chars_read = read_upgraded(buffer, fd);
	if (chars_read < 0)
		return (free(*ret), GNL_ERR);
	if (chars_read < BUFFER_SIZE && analyse_buffer(buffer) == NO_BR_BUFFER)
	{
		realloc_plus(ret, buffer, chars_read);
		buffer[0] = 0;
		return (GNL_OK);
	}
	else if (analyse_buffer(buffer) == NO_BR_BUFFER)
	{
		realloc_plus(ret, buffer, chars_read);
		buffer[0] = 0;
		return (gnl_rec(ret, buffer, fd));
	}
	br_dir = ft_strchr(buffer, '\n');
	if (realloc_plus(ret, buffer, br_dir - buffer + 1) == GNL_ERR)
		return (GNL_ERR); // +1 porque tiene que contar el /n. REALLOC PLUS TIENE QUE METER EL /0
	ft_memmove(buffer, br_dir + 1, BUFFER_SIZE - (br_dir - buffer + 1) + 1); //Quito los caracteres leidos y copio el /0.  Update buffer
	return (GNL_OK);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/*
int main(){
	int fd = open("texto.txt", O_RDONLY);
	char *ret = get_next_line(fd);
	printf("%s%d", ret, fd);
	free(ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	close(fd);
}
*/
