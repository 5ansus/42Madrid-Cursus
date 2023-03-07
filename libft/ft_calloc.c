/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:32:40 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/07 13:40:52 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;
	size_t	j;

	p = malloc(count * size);
	if(p == NULL)
		return NULL;
	i = 0;
	while(i < count)
	{
		j = 0;
		while(j < size)
		{
			p[i][j] = 0;
			j++;
		}
		i++;
	}
	return p;
}
