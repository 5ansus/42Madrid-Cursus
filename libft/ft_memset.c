/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:29:03 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/09 21:58:21 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*memset(void *b, int c, size_t len)
{
	char			*p;
	char			car;
	unsigned int	i;

	i = 0;
	car = c;
	p = (char *) b;
	while (i < len)
	{
		p[i] = car;
		i++;
	}
	return (b);
}
