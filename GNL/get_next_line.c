/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:03:44 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 16:23:24 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		n_chars_read;
	char		*ret;
	char		*end_line;

	if (buffer[0] == '\0')
	{
		return NULL;
	}
	n_chars_read = read(fd, &buffer, BUFFER_SIZE);
	if (n_chars_read < 0)
		return (NULL);
	buffer[n_chars_read] = '\0';
	end_line = ft_strchr(buffer, '\n');
	if (end_line != NULL)
		return (ft_substr(buffer, 0, (end_line - buffer) + 1));
}
