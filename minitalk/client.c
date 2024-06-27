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
int		set_signal_capture(void);
void	signal_capture(int signum);

int		g_sig_ack = 0;

int	main(int argc, char **argv)
{
	ssize_t	len_msg;
	ssize_t	i;
	int		pid;

	if (argc < 3)
	{
		ft_printf("Numero de argumentos incorrecto.");
		ft_printf("El cliente se usa de la siguiente forma:");
		ft_printf("\n\t./client <PID serv> <string>\n");
		return (0);
	}
	ft_printf("Se va a enviar: {%s}\n", argv[2]);
	if (set_signal_capture() != 0)
		return (1);
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
		g_sig_ack = 0;
		tmp = (letter << offset);
		if (tmp < 0)
			kill(pid, SIGUSR1);
		if (tmp >= 0)
			kill(pid, SIGUSR2);
		offset++;
		while (g_sig_ack == 0)
			;
		if (tmp < 0 && g_sig_ack != SIGUSR1)
			ft_printf("ERROR. Expected sig N10, got sig Nº%d\n", g_sig_ack);
		if (tmp >= 0 && g_sig_ack != SIGUSR2)
			ft_printf("ERROR. Expected sig N12, got sig Nº%d\n", g_sig_ack);
	}
}

void	send_len(ssize_t len, int pid)
{
	unsigned long	offset;
	ssize_t			tmp;

	offset = 0;
	while (offset < sizeof(ssize_t) * 8)
	{
		g_sig_ack = 0;
		tmp = (len << offset);
		if (tmp < 0)
			kill(pid, SIGUSR1);
		if (tmp >= 0)
			kill(pid, SIGUSR2);
		offset++;
		while (g_sig_ack == 0)
			;
		if (tmp < 0 && g_sig_ack != SIGUSR1)
			ft_printf("ERROR. Expected sig N10, got sig Nº%d\n", g_sig_ack);
		if (tmp >= 0 && g_sig_ack != SIGUSR2)
			ft_printf("ERROR. Expected sig N12, got sig Nº%d\n", g_sig_ack);
	}
}

int	set_signal_capture(void)
{
	struct sigaction	signal_struct;

	signal_struct.sa_handler = signal_capture;
	sigemptyset(&signal_struct.sa_mask);
	sigaddset(&signal_struct.sa_mask, SIGUSR1);
	sigaddset(&signal_struct.sa_mask, SIGUSR2);
	signal_struct.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &signal_struct, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &signal_struct, NULL) == -1)
		return (1);
	return (0);
}

void	signal_capture(int signum)
{
	g_sig_ack = signum;
}
