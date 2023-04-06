/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:10 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/06 14:59:48 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LEN_INT	12

void	ft_itoa_rec(int n, char *dest, int *index);

char	*ft_itoa(int n)
{
	char	str[MAX_LEN_INT];
	int		index;
	char	*ret;

	str[0] = '\0';
	index = 0;
	ft_itoa_rec(n, str, &index);
	ret = ft_strdup(str);
	return ret;
}

void	ft_itoa_rec(int n, char *dest, int *index)
{
	if (n < 0)
	{
		dest[*index] = '-';
		(*index)++;
		if((n / 10) != 0)
			ft_itoa_rec(-(n / 10), dest, index);
		dest[*index] = - (n % 10) + '0';
		dest[(*index) + 1] = '\0';
	}
	else
	{
		if((n / 10) != 0)
			ft_itoa_rec((n / 10), dest, index);
		dest[*index] = (n % 10) + '0';
		dest[(*index) + 1] = '\0';
		(*index)++;
	}
}
