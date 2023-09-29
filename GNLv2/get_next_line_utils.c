/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:04:48 by sanferna          #+#    #+#             */
/*   Updated: 2023/09/29 14:28:13 by sanferna         ###   ########.fr       */
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

char	analyse_buffer(char *dir)
{
	char return_value;

	return_value = ft_strchr(dir, '\n');
	if(return_value == dir)
		return EMPTY_BUFFER;
	if(return_value == NULL)
		return NO_BR_BUFFER;
	return BR_BUFFER;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	int		i;

	if (dst <= src || dst >= src + len)
		ft_memcpy(dst, src, len);
	else
	{
		dest = (char *) dst;
		source = (char *) src;
		i = len - 1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	return (dst);
}
