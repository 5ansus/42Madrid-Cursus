/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:16 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/14 17:09:22 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*dest;
	int		i;

	if (dst <= src || dst >= src + n)
		ft_memcpy(dst, src, n);
	else
	{
		dest = (char *) dst;
		source = (char *) src;
		i = n - 1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	return (dst);
}
