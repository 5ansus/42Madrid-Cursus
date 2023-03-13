/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:16 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/13 18:42:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*dst;
	int		i;
	if(dest <= src || dest >= src + n)
		ft_memcpy(dest, src, n);
	else
	{
		dst = (char *) dest;
		source = (char *) src;
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = source[i];
			i--;
		}	

	}
	return (dest);
}
