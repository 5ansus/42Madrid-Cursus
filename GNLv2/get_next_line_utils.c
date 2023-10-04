/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:04:48 by sanferna          #+#    #+#             */
/*   Updated: 2023/10/04 18:32:32 by sanferna         ###   ########.fr       */
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
	char *return_value;

	return_value = ft_strchr(dir, '\n');
	if(return_value == dir)
		return EMPTY_BUFFER;
	if(return_value == NULL)
		return NO_BR_BUFFER;
	return BR_BUFFER;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*dest;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	dest = (char *) dst;
	source = (char *) src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
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



char realloc_plus(char **dst, char *src, ssize_t chars)
{
	ssize_t	i;
	ssize_t	dst_len;
	char	*new_dst;

	if (*dst != NULL)
	{
		while ((*dst)[dst_len] != '\0')
			dst_len++;
		new_dst = malloc(dst_len + chars + 1);
		if (new_dst == NULL)
			return (free(*dst), GNL_ERR);
		ft_memmove(new_dst, *dst, dst_len);
		ft_memmove(new_dst + dst_len, src, chars);
		new_dst[dst_len + chars] = '\0';
	}
	else{
		new_dst = malloc(chars + 1);
		if (new_dst == NULL)
			return (GNL_ERR);
		ft_memmove(new_dst, src, chars);
		new_dst[chars] = '\0';
	}
	*dst = new_dst;
	return GNL_OK;
}
