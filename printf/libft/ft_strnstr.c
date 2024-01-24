/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:11 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/22 16:42:31 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ret;
	size_t	len_obj;
	size_t	offset;

	len_obj = ft_strlen(needle);
	if (len_obj == 0)
		return ((char *) haystack);
	ret = ft_strchr(haystack, needle[0]);
	while (ret != NULL)
	{
		offset = ret - haystack;
		if ((offset + len_obj > len))
			return (NULL);
		if (ft_strncmp(needle, ret, len_obj) == 0)
			return (ret);
		ret = ft_strchr(ret + 1, needle[0]);
	}
	return (NULL);
}
