/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:56:56 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/05 18:44:19 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	res_len;
	size_t	i;
	char	*ret;

	i = 0;
	str_len = ft_strlen(s);
	if (str_len < start)
		res_len = 0;
	else if ((str_len - start) > len)
		res_len = len;
	else
		res_len = (str_len - start);
	ret = malloc((res_len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < res_len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
