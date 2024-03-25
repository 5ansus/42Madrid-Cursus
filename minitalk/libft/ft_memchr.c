/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:50:30 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/22 16:41:54 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*p;
	size_t			i;
	unsigned char	car;

	i = 0;
	car = c;
	p = (char *) s;
	while (i < n)
	{
		if ((unsigned char) p[i] == car)
			return ((char *) &p[i]);
		i++;
	}
	return (NULL);
}
