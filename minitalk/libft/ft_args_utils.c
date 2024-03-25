/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:26:26 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/22 21:56:45 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*analyze_args(char *p_str, va_list lst, int *zeros)
{
	char	*new_str;
	char	*next_pct;
	char	mod;
	char	*temp;

	new_str = NULL;
	next_pct = ft_strchr(p_str, '%');
	while (next_pct != NULL)
	{
		realloc_printf(&new_str, p_str, next_pct - p_str, zeros);
		p_str = next_pct + 2;
		mod = *(next_pct + 1);
		temp = NULL;
		save_arg_chars(mod, lst, &temp, zeros);
		save_arg_numeric(mod, lst, &temp, zeros);
		if (temp == NULL)
			return (free(new_str), NULL);
		if (realloc_printf(&new_str, temp, ft_strlen(temp), zeros) == GNL_ERR)
			return (free(temp), free(new_str), NULL);
		free(temp);
		next_pct = ft_strchr(p_str, '%');
		if (next_pct == NULL)
			realloc_printf(&new_str, p_str, ft_strlen(p_str), zeros);
	}
	return (new_str);
}

void	save_arg_numeric(char mod, va_list lst, char **ret, int *count_zeros)
{
	t_arg_types	arg;
	int			conv_mod;

	conv_mod = -1;
	if (mod == 'd' || mod == 'i' || mod == 'x' || mod == 'X')
		arg.i = va_arg(lst, int);
	if (mod == 'p')
		arg.ul = va_arg(lst, unsigned long long);
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

void	save_arg_chars(char mod, va_list lst, char **ret, int *count_zeros)
{
	char	*p;

	p = NULL;
	if (mod == '%' || mod == 'c')
	{
		*ret = malloc(2);
		(*ret)[0] = '%';
		if (mod != '%')
			(*ret)[0] = va_arg(lst, int);
		if ((*ret)[0] == '\0')
		{
			*count_zeros = *count_zeros + 1;
			realloc_printf(ret, "\0", 1, count_zeros);
		}
		(*ret)[1] = '\0';
	}
	if (mod == 's')
	{
		p = va_arg(lst, char *);
		if (p == NULL)
			realloc_printf(ret, "(null)", ft_strlen("(null)"), count_zeros);
		if (p != NULL)
			realloc_printf(ret, p, ft_strlen(p), count_zeros);
	}
}
