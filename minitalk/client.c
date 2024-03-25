/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:43 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 21:41:27 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	transmit_char(int letter, int pid);
void	send_len(ssize_t len, int pid);

int	main(int argc, char **argv)
{
	ssize_t	len_msg;
	ssize_t	i;
	int		pid;

	if (argc < 2)
	{
		ft_printf("Numero de argumentos incorrecto.");
		ft_printf("El cliente se usa de la siguiente forma:");
		ft_printf("\n\t./client <PID serv> <string>\n");
		return (0);
	}
	len_msg = ft_strlen(argv[2]);
	i = 0;
	pid = ft_atoi(argv[1]);
	send_len(len_msg, pid);
	while (i < len_msg)
	{
		transmit_char(argv[2][i], pid);
		i++;
	}
	transmit_char(0, pid);
	return (0);
}

void	transmit_char(int letter, int pid)
{
	int	offset;
	int	tmp;

	offset = 24;
	while (offset < 32)
	{
		tmp = (letter << offset);
		if (tmp < 0)
			kill(pid, SIGUSR1);
		if (tmp >= 0)
			kill(pid, SIGUSR2);
		offset++;
		usleep(50);
	}
}

void	send_len(ssize_t len, int pid)
{
	unsigned long	offset;
	ssize_t			tmp;

	offset = 0;
	while (offset < sizeof(ssize_t))
	{
		tmp = (len << offset);
		if (tmp < 0)
			kill(pid, SIGUSR1);
		if (tmp >= 0)
			kill(pid, SIGUSR2);
		offset++;
		usleep(50);
	}
}
