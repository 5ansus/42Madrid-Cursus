/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:05 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/04 19:03:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	front;
	size_t	back;
	char	*ret;

	front = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (front < len && ft_strchr(set, s1[front]))
		front++;
	back = len - 1;
	while (back >= 0 && ft_strchr(set, s1[back]))
		back--;
	back = (len - 1) - back;
	if (back + front > len)
		return (ft_strdup(""));
	ret = malloc((len - front - back + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, &s1[front], (len - front - back + 1));
	return (ret);
}
