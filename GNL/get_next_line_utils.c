/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:31:59 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/10 16:00:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	int				len;
	const char		*p;
	unsigned char	car;

	i = 0;
	car = c;
	len = ft_strlen(s);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	res_len;
	size_t	i;
	char	*ret;

	i = 0;
	str_len = ft_strlen(s);
	if (str_len < start)
		res_len = 0;
	else if ((str_len - start) > len)
		res_len = len;
	else
		res_len = (str_len - start);
	ret = malloc((res_len + 1) * sizeof (char));
	if (ret == NULL)
		return (NULL);
	while (i < res_len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	ret = malloc ((len + 1) * sizeof (char));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while ((i < len_src) && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cpy_size;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	if (dstsize - 1 >= len_dst + len_src)
		cpy_size = len_src;
	else
		cpy_size = dstsize - len_dst - 1;
	ft_memmove(dst + len_dst, src, cpy_size);
	dst[len_dst + cpy_size] = '\0';
	return (len_src + len_dst);
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
