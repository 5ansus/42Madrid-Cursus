/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:14:27 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 16:02:03 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif
