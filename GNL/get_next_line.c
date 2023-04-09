/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:26:50 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			n_chars_read;
	char		*ret;

	//Learning purposes: printf("PREVIO: %s\n", buffer);
	n_chars_read = read(fd, &buffer, BUFFER_SIZE);
	buffer[n_chars_read] = '\0';
	ret = ft_strdup(buffer);
	return (ret);
}
