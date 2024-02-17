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
char	*analyze_args(char *p_str, va_list lst);
void save_arg_chars(char mod, va_list lst, char **ret);
void save_arg_numeric(char mod, va_list lst, char **ret);

int ft_printf(char const *str, ...)
{
	va_list lista;
	char	*ret_str;
	ssize_t	ret;
	char	*str_cpy;

	str_cpy = (char *)str;
	ret_str = NULL;
	ret = 0;
	if (ft_strlen(str_cpy) == 0)
		return (0);
	if (ft_strchr(str_cpy, '%') == NULL)
		ret = write(1, str_cpy, ft_strlen(str));
	else
	{
		va_start(lista, str);
		ret_str = analyze_args(str_cpy, lista);
		va_end(lista);
		if (ret_str != NULL)
		{
			ret = write(1, ret_str, ft_strlen(ret_str));
			free(ret_str);
		}
	}
	return (ret);
}

char	*analyze_args(char *p_str, va_list lst)
{
	char *new_str;
	char *next_pct;
	char mod;
	char *temp_str;

	new_str = NULL;
	next_pct = ft_strchr(p_str, '%');
	while (next_pct != NULL)
	{
		realloc_plus(&new_str, p_str, next_pct - p_str);
		p_str = next_pct + 2;
		mod = *(next_pct + 1);
		temp_str = NULL;
		save_arg_chars(mod, lst, &temp_str);
		save_arg_numeric(mod, lst, &temp_str);
		if (temp_str == NULL)
			return (free(new_str), NULL);
		if(realloc_plus(&new_str, temp_str, ft_strlen(temp_str)) == GNL_ERR)
			return(free(temp_str), free(new_str), NULL);
		free(temp_str);
		next_pct = ft_strchr(p_str, '%');
		if (next_pct == NULL)
			realloc_plus(&new_str, p_str, ft_strlen(p_str));
	}
	return new_str;
}

void save_arg_numeric(char mod, va_list lst, char **ret)
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
		cnv(arg, conv_mod, ret);
}

void save_arg_chars(char mod, va_list lst, char **ret)
{
	char *p;

	p = NULL;
	if (mod == '%')
	{
		*ret = malloc(2);
		if (*ret == NULL)
			return;
		(*ret)[0] = '%';
		(*ret)[1] = '\0';
	}
	if (mod == 'c')
	{
		*ret = malloc(2);
		if (*ret == NULL)
			return;
		(*ret)[0] = va_arg(lst, int);
		(*ret)[1] = '\0';
	}
	if (mod == 's')
	{
		p = va_arg(lst, char *);
		if (p == NULL)
			realloc_plus(ret, "(null)", ft_strlen("(null)"));
		if (p != NULL && *p != '\0')
			realloc_plus(ret, p, ft_strlen(p));
		if (p != NULL && *p == '\0')
			realloc_plus(ret, p, 0);
	}
}
