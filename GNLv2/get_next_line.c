/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:03:47 by sanferna          #+#    #+#             */
/*   Updated: 2023/10/11 16:48:25 by sanferna         ###   ########.fr       */
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
		if (ft_strchr(ret, '\0') == ret)
			return (free(ret), NULL);
		return (ret);
	}
	return (NULL);
}

ssize_t	read_upgraded(char *buffer, int fd, char *read_complete)
{
	ssize_t	chars_read;

	chars_read = read(fd, buffer, BUFFER_SIZE);
	*read_complete = (chars_read == BUFFER_SIZE);
	if (chars_read >= 0)
		buffer[chars_read] = 0;
	return (chars_read);
}

char	gnl_rec(char **ret, char *buffer, int fd)
{
	ssize_t	chars_read;
	char	*br_dir;
	char	read_complete;

	read_complete = 1;
	chars_read = ft_strlen(buffer);
	if (buffer[0] == 0)
		chars_read = read_upgraded(buffer, fd, &read_complete);
	if (chars_read < 0)
		return (free(*ret), GNL_ERR);
	if (read_complete == 0 && analyse_buffer(buffer) == NO_BR_BUFFER)
	{
		realloc_plus(ret, buffer, chars_read);
		return (buffer[0] = 0, GNL_OK);
	}
	else if (analyse_buffer(buffer) == NO_BR_BUFFER)
	{
		realloc_plus(ret, buffer, chars_read);
		return (buffer[0] = 0, gnl_rec(ret, buffer, fd));
	}
	br_dir = ft_strchr(buffer, '\n');
	if (realloc_plus(ret, buffer, br_dir - buffer + 1) == GNL_ERR)
		return (GNL_ERR);
	ft_memmove(buffer, br_dir + 1, BUFFER_SIZE - (br_dir - buffer + 1) + 1);
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
