/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:44:15 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/22 17:00:56 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '+' || str[i] == '-');
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nb = nb * 10;
		if (sign == -1)
			nb -= str[i] - '0';
		else
			nb += str[i] - '0';
		i++;
	}
	return (nb);
}

int	ft_isspace(int c)
{
	int				ret;
	unsigned char	car;

	car = c;
	ret = (car == ' ');
	ret += (car == '\t');
	ret += (car == '\n');
	ret += (car == '\r');
	ret += (car == '\v');
	ret += (car == '\f');
	return (ret);
}
