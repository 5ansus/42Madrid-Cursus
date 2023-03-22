/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:55:22 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/22 16:42:20 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
