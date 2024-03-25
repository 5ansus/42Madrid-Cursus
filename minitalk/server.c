/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:36 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 19:24:14 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	signal_capture(int signum);
int		set_signal_capture(void);
t_handler_buffer	g_buffer;

int	main(int argc, char **argv)
{
	if (set_signal_capture() != 0)
		return (1);
	ft_printf("PID del servidor: %d\n", getpid());
	g_buffer.value = 0;
	g_buffer.count = 0;
	while (1)
		usleep(75);
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
	g_buffer.value = g_buffer.value << 1;
	if (signum == SIGUSR1)
		g_buffer.value += 1;
	g_buffer.count += 1;
	if (g_buffer.count >= 8)
	{
		if (g_buffer.value != 0)
			ft_printf("%c", g_buffer.value);
		if (g_buffer.value == 0)
			ft_printf("\n");
		g_buffer.count = 0;
		g_buffer.value = 0;
	}
}
