/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:43 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 15:34:18 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char *argv)
{
	ssize_t	len_msg;
	ssize_t	i;
	int	pid;

	if (argc < 2)
	{
		ft_printf("Numero de argumentos incorrecto.\n \
			El cliente se usa de la siguiente forma: \
			./client <PID serv> <string>\n");
	}
	len_msg = ft_strlen(argv[2]);
	i = 0;
	pid = ft_atoi(argv[1]);
	while(i < len_msg)
	{

	}
}

void	transmit_char(char c, int pid)
{
	int i;

	i = 0;
}
