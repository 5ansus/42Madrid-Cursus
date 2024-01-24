/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:32:59 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/05 20:19:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if ((n / 10) != 0)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd('0' + (-(n % 10)), fd);
	}
	else if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		if ((n / 10) != 0)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}
