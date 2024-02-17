/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/17 20:01:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

#include <stdio.h>
char	*analyze_args(char *p_str, va_list lst, int *count_zeros);
void save_arg_chars(char mod, va_list lst, char **ret, int *count_zeros);
void save_arg_numeric(char mod, va_list lst, char **ret, int *count_zeros);
ssize_t printf_strlen(char **dst, int *count_zeros);


int ft_printf(char const *str, ...)
{
	va_list lista;
	char	*ret_str;
	ssize_t	ret;
	char	*str_cpy;
	int count_zeros;

	str_cpy = (char *)str;
	ret_str = NULL;
	ret = 0;
	count_zeros = 0;
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
		{
			ret = write(1, ret_str, ft_strlen(ret_str));
			free(ret_str);
		}
	}
	return (ret);
}

char	*analyze_args(char *p_str, va_list lst, int *count_zeros)
{
	char *new_str;
	char *next_pct;
	char mod;
	char *temp_str;

	new_str = NULL;
	next_pct = ft_strchr(p_str, '%');
	while (next_pct != NULL)
	{
		realloc_plus_printf(&new_str, p_str, next_pct - p_str, count_zeros);
		p_str = next_pct + 2;
		mod = *(next_pct + 1);
		temp_str = NULL;
		save_arg_chars(mod, lst, &temp_str, count_zeros);
		save_arg_numeric(mod, lst, &temp_str, count_zeros);
		if (temp_str == NULL)
			return (free(new_str), NULL);
		if(realloc_plus_printf(&new_str, temp_str, ft_strlen(temp_str), count_zeros) == GNL_ERR)
			return(free(temp_str), free(new_str), NULL);
		free(temp_str);
		next_pct = ft_strchr(p_str, '%');
		if (next_pct == NULL)
			realloc_plus_printf(&new_str, p_str, ft_strlen(p_str), count_zeros);
	}
	return new_str;
}

void save_arg_numeric(char mod, va_list lst, char **ret, int *count_zeros)
{
	t_arg_types arg;
	int	conv_mod;

	conv_mod = -1;
	if (mod == 'd' || mod == 'i' || mod == 'x' || mod == 'X')
		arg.i = va_arg(lst, int);
	if (mod == 'p')
		arg.ul = (unsigned long long) va_arg(lst, void *);
	if (mod == 'u')
		arg.u = va_arg(lst, unsigned int);
	if (mod == 'd' || mod == 'i')
		conv_mod = TO_INT;
	if (mod == 'p')
		conv_mod = TO_POINTER;
	if (mod == 'u')
		conv_mod = TO_UNS;
	if (mod == 'x')
		conv_mod = TO_HEX_MIN;
	if (mod == 'X')
		conv_mod = TO_HEX_CAPS;
	if (conv_mod >= 0)
		cnv(arg, conv_mod, ret, count_zeros);
}

void save_arg_chars(char mod, va_list lst, char **ret, int *count_zeros)
{
	char *p;

	p = NULL;
	if (mod == '%' || mod == 'c')
	{
		*ret = malloc(2);
		if (*ret == NULL)
			return;

		(*ret)[0] = '%';
		if (mod != '%')
			(*ret)[0] = va_arg(lst, int);
		if ((*ret)[0] == '\0')
		{
			*count_zeros = *count_zeros + 1;
			realloc_plus_printf(ret, "\0", 1, count_zeros);
		}
		(*ret)[1] = '\0';
	}
	if (mod == 's')
	{
		p = va_arg(lst, char *);
		if (p == NULL)
			realloc_plus_printf(ret, "(null)", ft_strlen("(null)"), count_zeros);
		if (p != NULL)
			realloc_plus_printf(ret, p, ft_strlen(p), count_zeros);
		// if (p != NULL && *p != '\0')
		// 	realloc_plus_printf(ret, p, ft_strlen(p));
		// if (p != NULL && *p == '\0')
		// 	realloc_plus_printf(ret, p, 0);
	}
}

char	realloc_plus_printf(char **dst, char *src, ssize_t chars, int *count_zeros)
{
	ssize_t	dst_len;
	char	*new_dst;

	dst_len = 0;
	if (*dst != NULL)
	{
		dst_len = printf_strlen(dst, count_zeros);
		new_dst = malloc(dst_len + chars + 1);
		if (new_dst == NULL)
			return (free(*dst), GNL_ERR);
		ft_memmove(new_dst, *dst, dst_len);
		ft_memmove(new_dst + dst_len, src, chars);
		new_dst[dst_len + chars] = '\0';
		free(*dst);
	}
	else
	{
		new_dst = malloc(chars + 1);
		if (new_dst == NULL)
			return (GNL_ERR);
		ft_memmove(new_dst, src, chars);
		new_dst[chars] = '\0';
	}
	return (*dst = new_dst, GNL_OK);
}

ssize_t printf_strlen(char **dst, int *count_zeros)
{
	int i;
	ssize_t len;

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
