/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:13:10 by sanferna          #+#    #+#             */
/*   Updated: 2023/07/06 12:57:13 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	//ssize_t		chars_read;
	char		*ret;

	ret = NULL;
	printf("Buffer antes de hacer cosas:%s\n", buffer);
	do_things_buffer(&ret, buffer, fd);
	return (ret);
}
