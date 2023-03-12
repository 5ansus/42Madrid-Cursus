/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:17:38 by sanferna          #+#    #+#             */
/*   Updated: 2023/03/09 23:24:47 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>

int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isalpha(int c);
void	ft_putstr_fd(char *s, int fd);
#endif
