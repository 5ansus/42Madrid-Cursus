/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/22 21:51:34 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	printf_strlen(char **dst, int *count_zeros);

int	ft_printf(char const *str, ...)
{
	va_list	lista;
	char	*ret_str;
	ssize_t	ret;
	char	*str_cpy;
	int		count_zeros;

	str_cpy = (char *)str;
	ret_str = NULL;
	count_zeros = 0;
	ret = 0;
	if (ft_strlen(str_cpy) == 0)
		return (0);
	if (ft_strchr(str_cpy, '%') == NULL)
		ret = write(1, str_cpy, ft_strlen(str));
	else
	{
		va_start(lista, str);
		ret_str = analyze_args(str_cpy, lista, &count_zeros);
		va_end(lista);
		if (ret_str != NULL)
			ret = write(1, ret_str, printf_strlen(&ret_str, &count_zeros));
	}
	return (free(ret_str), ret);
}

char	realloc_printf(char **dst, char *src, ssize_t size, int *zeros)
{
	ssize_t	dst_len;
	char	*new_dst;

	dst_len = 0;
	if (*dst != NULL)
	{
		dst_len = printf_strlen(dst, zeros);
		new_dst = malloc(dst_len + size + 1);
		if (new_dst == NULL)
			return (free(*dst), GNL_ERR);
		ft_memmove(new_dst, *dst, dst_len);
		ft_memmove(new_dst + dst_len, src, size);
		new_dst[dst_len + size] = '\0';
		free(*dst);
	}
	else
	{
		new_dst = malloc(size + 1);
		if (new_dst == NULL)
			return (GNL_ERR);
		ft_memmove(new_dst, src, size);
		new_dst[size] = '\0';
	}
	return (*dst = new_dst, GNL_OK);
}

ssize_t	printf_strlen(char **dst, int *count_zeros)
{
	int		i;
	ssize_t	len;

	i = 0;
	len = 0;
	while (i <= *count_zeros)
	{
		while ((*dst)[len] != '\0')
			len++;
		i++;
		if (i <= *count_zeros)
			len++;
	}
	return (len);
}
