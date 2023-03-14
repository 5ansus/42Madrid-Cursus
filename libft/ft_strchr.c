/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:33:07 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/14 22:17:27 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	car;
	const char 		*p;

	i = 0;
	car = c;
	if (car > 255)
		return ((char *) s);
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		p = s + i;
		return ((char *)p);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c){
			p = s + i;
			return ((char *)p);
		}
		i++;
	}
	return (NULL);
}
