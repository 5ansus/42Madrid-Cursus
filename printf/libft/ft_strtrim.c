/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:05 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/05 16:47:48 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_new_len(char const *s, char const *set, size_t *offset);
static size_t	ft_front_offset(char const *s, char const *set, size_t len);
static size_t	ft_back_offset(char const *s, char const *set, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_len;
	size_t	start;
	char	*ret;

	new_len = ft_get_new_len(s1, set, &start);
	if (new_len == 0)
		return (ft_strdup(""));
	ret = ft_substr(s1, start, new_len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

static size_t	ft_get_new_len(char const *s, char const *set, size_t *offset)
{
	size_t	len;
	size_t	front;
	size_t	back;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	front = ft_front_offset(s, set, len);
	if (front == len)
		return (0);
	back = ft_back_offset(s, set, len);
	*offset = front;
	return (len - front - back);
}

static size_t	ft_front_offset(char const *s, char const *set, size_t len)
{
	size_t	ret;

	ret = 0;
	len = ft_strlen(s);
	while (ret < len && ft_strchr(set, s[ret]))
		ret++;
	return (ret);
}

static size_t	ft_back_offset(char const *s, char const *set, size_t len)
{
	size_t	ret;

	len = ft_strlen(s);
	ret = len;
	while (ret > 0 && ft_strchr(set, s[ret - 1]))
		ret--;
	ret = len - ret;
	return (ret);
}
