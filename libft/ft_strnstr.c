/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:11 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/21 16:55:21 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ret;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	while (ret = ft_strchr(haystack, needle[0]))
	{
		if ((ret + len_needle - haystack < len) && ft_strncmp(needle, ret, len_needle) == 0)
			return (ret);
	}
	return (NULL);
}
