/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:32:40 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/12 18:47:31 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ft_memset(p + (size * i), 0, size);
		i++;
	}
	return (p);
}
