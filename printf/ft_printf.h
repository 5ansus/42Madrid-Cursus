/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:58:54 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/03 22:05:46 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
typedef union u_arg_types
{
	int					i;
	unsigned int		u;
	unsigned long long	p;
	char				c;
}			t_arg_types;

#define TO_INT 0
#define TO_UNS 1
#define TO_HEX_MIN 2
#define TO_HEX_CAPS 3
#define TO_POINTER 4

int	ft_printf(char const *str, ...);
void	cnv(t_arg_types num, char mode, char **ret);
#endif
