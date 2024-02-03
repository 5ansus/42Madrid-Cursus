/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/03 22:14:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	va_list lista;
	ssize_t ret;

	t_arg_types arg;
	char* new_str;

	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strchr(str, '%') == NULL)
		ret = write(0, str, ft_strlen(str));
	else
	{
		va_start(lista, str);
		//ret = analyze_args(str, lista);

		// arg.c = va_arg(lista, int);
		// realloc_plus(&new_str, (char *) &arg.c, 1);
		// printf("%s\n", new_str);
		// free(new_str);
		va_end(lista);
	}
	return (ret);
}

ssize_t	analyze_args(char *p_str, va_list lst)
{
	char *new_str;
	char *next_pct;
	t_arg_types arg;
	char	mod;

	new_str = NULL;
	next_pct = ft_strchr(p_str, '%');
	while(next_pct != NULL)
	{
		realloc_plus(&new_str, p_str, next_pct - p_str);
		p_str = next_pct + 2;
		mod = *next_pct + 1;
		if (mod == 'c')
			arg.c = va_arg(lst, int);
		if (mod == 'd' || mod == 'i' || mod == 'x' || mod == 'X')
			arg.i = va_arg(lst, int);
		if (mod == 'p')
			arg.i = va_arg(lst, void *);
		if (mod == 's')
			arg.i = va_arg(lst, char *);
		if (mod == 'u')
			arg.u = va_arg(lst, char *);
		if (mod == '%')
			arg.i = va_arg(lst, char *);
		next_pct = ft_strchr(p_str, '%');
	}
	return 0;
}
