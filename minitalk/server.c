/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:36 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 18:44:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

t_handler_buffer buffer;
void	signal_capture(int signum);
int	set_signal_capture();
int main()
{
	if (set_signal_capture() != 0)
		return (1);
	ft_printf("PID derl servidor_: %d\n", getpid());
	while(1);
}

int	set_signal_capture()
{
	struct sigaction signal_struct;

	signal_struct.sa_handler = signal_capture;
	sigemptyset(&signal_struct.sa_mask);
	sigaddset(&signal_struct.sa_mask, SIGUSR1);
	sigaddset(&signal_struct.sa_mask, SIGUSR2);
	signal_struct.sa_flags = SA_RESTART;
	if(sigaction(SIGUSR1, &signal_struct, NULL) == -1)
		return(1);
	if(sigaction(SIGUSR2, &signal_struct, NULL) == -1)
		return(1);
	return(0);
}

void signal_capture(int signum)
{
	ft_printf("Señal capturada %d\n", signum);
	if(buffer.count == 0) buffer.value = 0;
	if(signum == SIGUSR1) buffer.value += 1;
	buffer.count += 1;
	buffer.value = buffer.value << 1;
	if(buffer.count >= 8)
	{
		if(buffer.value != 0) ft_printf("%c", (char) buffer.value);
		if(buffer.value == 0) ft_printf("\n");
		buffer.count = 0;
	}
}
