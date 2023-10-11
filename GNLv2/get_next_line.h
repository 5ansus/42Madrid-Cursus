/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:13:06 by sanferna          #+#    #+#             */
/*   Updated: 2023/10/11 16:55:35 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define EMPTY_BUFFER 0
# define NO_BR_BUFFER 1
# define BR_BUFFER 2
# define GNL_OK 1
# define GNL_ERR 0

char	*get_next_line(int fd);
char	analyse_buffer(char *dir);
ssize_t	read_upgraded(char *buffer, int fd, char *read_complete);
char	realloc_plus(char **dst, char *src, ssize_t chars);
char	gnl_rec(char **ret, char *buffer, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
