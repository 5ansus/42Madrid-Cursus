/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:26:50 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 16:02:20 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			n_chars_read;
	char		*ret;

	if (buffer[0] != '\0') printf("PREVIO: %s\n", buffer);
	n_chars_read = read(fd, &buffer, BUFFER_SIZE);
	buffer[n_chars_read] = '\0';
	ret = ft_strdup(buffer);
	return (ret);
}
