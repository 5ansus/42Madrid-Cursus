/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:51:20 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/05 18:46:39 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
/*static size_t	ft_count_words(char const *s, char sep);
static size_t	ft_get_len(char const *s, char sep);*/
static size_t	ft_count_words(char const *s, char *set);
static size_t	**ft_aux(char const *s, char *set, size_t nWords);
//static void	*ft_realloc(void *mem, size_t size);

char	**ft_split(char const *s, char c)
{
	char	*trimmed;
	char	set[8];
	char	**ret;
	size_t	**aux;
	size_t	i;

	set[0] = c;
	set[1] = '\0';
	trimmed = ft_strtrim(s, set);
	size_t tam = ft_count_words(trimmed, set);
	if (ft_strlen(trimmed) == 0)
	{
		free(trimmed);
		ret = ft_calloc(1, sizeof(char *));
		return (ret);
	}
	aux = ft_aux(trimmed, set, tam);
	if(aux == NULL)
	{
		free(trimmed);
		return(NULL);
	}
	i = 0;
	ret = calloc (tam + 1, sizeof(char *));

	while (i < tam)
	{
		ret[i] = ft_substr(trimmed, aux[i][0], aux[i][1]);
		free(aux[i]);
		i++;
	}
	free(aux);
	free(trimmed);
	return (ret);
}

static size_t	**ft_aux(char const *s, char *set, size_t nWords)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	size_t	**ret;

	i = 0;
	j = 0;
	ret = malloc(nWords * sizeof(size_t *));
	if(ret == NULL)
		return (NULL);
	while(s[i] != '\0')
	{
		ret[j] = malloc(2 * sizeof(size_t));
		if(ret[j] == NULL)
		{
			i = 0;
			while(i < j){
				free(ret[i]);
				i++;
			}
			free(ret);
		}
		while(s[i] != '\0' && ft_strchr(set, s[i]) != NULL)
			i++;
		temp = i;
		ret[j][0] = i;
		while(s[i] != '\0' && ft_strchr(set, s[i]) == NULL)
			i++;
		ret[j][1] = i - temp;
		j++;
	}
	return (ret);
}

static size_t	ft_count_words(char const *s, char *set){
	size_t	i;
	size_t nWords;

	nWords = 0;
	i = 0;
	while(s[i] != '\0')
	{
		while(s[i] != '\0' && ft_strchr(set, s[i]) != NULL)
			i++;
		nWords++;
		while(s[i] != '\0' && ft_strchr(set, s[i]) == NULL)
			i++;
	}
	return (nWords);
}
