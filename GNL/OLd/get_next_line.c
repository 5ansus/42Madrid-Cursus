/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:03:44 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/14 12:02:54 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		n_chars_read;
	char		*ret;
	char		*end_line;

	ret = NULL;
	if (buffer[0] != 0)
	{

	}
	while(1){
		n_chars_read = read(fd, &buffer, BUFFER_SIZE);
		if(n_chars_read < 0)
			return (free(ret), NULL);
		buffer[n_chars_read] = '\0';
		if (ft_strchr(buffer, '\n') == NULL)
			ret = ft_realloc();
		else{
			ret = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1); //llevas realloc? -- Reimplementar
			if (ret == NULL)
				return (NULL);
			ft_strlcpy(buffer, ft_strchr(buffer, '\n') + 1, ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
			return (ret);
		}
	}
}
