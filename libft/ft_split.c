/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:51:20 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/05 20:19:34 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**ret;
	size_t	i;
	size_t	temp;
	size_t	j;

	n_words = ft_count_words(s, c);
	ret = ft_calloc(n_words + 1, sizeof(char *));
	if (n_words == 0 || ret == NULL)
		return (ret);
	i = 0;
	j = 0;
	while (j < n_words)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] == 0)
			return (ret);
		temp = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		ret[j] = ft_substr(s, temp, i - temp);
		j++;
	}
	return (ret);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] == 0)
			return (count);
		while (s[i] != 0 && s[i] != c)
			i++;
		count++;
	}
	return (count);
}
