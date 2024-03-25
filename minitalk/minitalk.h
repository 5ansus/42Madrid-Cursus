/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:25:15 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/25 21:41:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

typedef struct s_server
{
	ssize_t	len;
	int		len_len;
	char	*str;
	int		sig_count;
	int		char_value;
	int		status;
}			t_server;

#endif
