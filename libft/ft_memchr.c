/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:50:30 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/18 18:53:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*input;
	char		*ret;

	input = (char *) s;
	ret = ft_strchr(input,(unsigned int) c);
	if ((size_t) (ret - input) < n)
		return ((void *)ret);
	return (NULL);
}*/

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
