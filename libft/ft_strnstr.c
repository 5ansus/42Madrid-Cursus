/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:11 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/21 15:56:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_haystack;
	size_t	len_needle;
	size_t	i;	
	size_t	j;

	i = 0;
	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0]){
		
		}
	}
	return (NULL);
}
