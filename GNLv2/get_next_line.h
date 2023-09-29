/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:13:06 by sanferna          #+#    #+#             */
/*   Updated: 2023/09/29 14:28:36 by sanferna         ###   ########.fr       */
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

/*# define END_OF_FILE 1
# define READ_CHASH -1
# define NORMAL_BUFFER 0
# define BUFFER_WITH_BREAK 2*/
# define EMPTY_BUFFER 0
# define NO_BR_BUFFER 1
# define BR_BUFFER 2

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
#endif
