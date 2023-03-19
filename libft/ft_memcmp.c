/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:03:04 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/19 20:08:14 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *) s1;
	b = (char *) s2;
	while (i < n && a[i] == b[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char) a[i]) - ((unsigned char) b[i]));
}
