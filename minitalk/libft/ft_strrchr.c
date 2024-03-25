/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:33:14 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/22 16:42:34 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	const char		*p;
	unsigned char	car;

	i = ft_strlen(s);
	car = c;
	while (i >= 0)
	{
		if ((unsigned int) s[i] == car)
		{
			p = s + i;
			return ((char *)p);
		}
		i--;
	}
	return (NULL);
}
