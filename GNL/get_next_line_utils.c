/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:31:59 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 16:18:51 by sanferna         ###   ########.fr       */
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
