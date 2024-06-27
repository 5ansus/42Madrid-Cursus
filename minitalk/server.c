/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:36 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 22:12:37 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	signal_capture(int signum, siginfo_t *info, void *ucontext);
int		set_signal_capture(void);
void	process_len(int signum);
static t_server	g_srv;

int	main(void)
{
	if (set_signal_capture() != 0)
		return (1);
	ft_printf("PID del servidor: %d\n", getpid());
	g_srv.len = 0;
	g_srv.len_len = 0;
	g_srv.sig_count = 0;
	g_srv.str = NULL;
	g_srv.char_value = 0;
	g_srv.status = 0;
	while (1)
	{
		if (g_srv.status != 0)
			return (1);
	}
	return (0);
}

int	set_signal_capture(void)
{
	struct sigaction	signal_struct;

	signal_struct.sa_sigaction = signal_capture;
	sigemptyset(&signal_struct.sa_mask);
	sigaddset(&signal_struct.sa_mask, SIGUSR1);
	sigaddset(&signal_struct.sa_mask, SIGUSR2);
	signal_struct.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &signal_struct, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &signal_struct, NULL) == -1)
		return (1);
	return (0);
}

void	signal_capture(int signum, siginfo_t *info, void *ucontext)
{
	if (g_srv.str == NULL)
		process_len(signum);
	else
	{
		g_srv.char_value = g_srv.char_value << 1;
		if (signum == SIGUSR1)
			g_srv.char_value += 1;
		g_srv.sig_count += 1;
		if (g_srv.sig_count == 8 && (ucontext == NULL || ucontext != NULL))
		{
			if (g_srv.char_value != 0)
				g_srv.str[g_srv.len] = g_srv.char_value;
			if (g_srv.char_value == 0)
			{
				ft_printf("%s\n", g_srv.str);
				free(g_srv.str);
				g_srv.str = NULL;
				g_srv.len = 0;
			}
			g_srv.len++;
			g_srv.sig_count = 0;
			g_srv.char_value = 0;
		}
	}
	kill(info->si_pid, signum);
}

void	process_len(int signum)
{
	g_srv.len = g_srv.len << 1;
	if (signum == SIGUSR1)
		g_srv.len += 1;
	g_srv.len_len++;
	if (g_srv.len_len == sizeof(ssize_t) * 8)
	{
		g_srv.str = malloc(g_srv.len + 1);
		if (g_srv.str == NULL)
		{
			g_srv.status = 1;
			return ;
		}
		g_srv.str[g_srv.len] = '\0';
		g_srv.len_len = 0;
		g_srv.len = 0;
	}
}
