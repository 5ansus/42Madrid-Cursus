/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticTest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:34:23 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/10 15:11:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*gcc -Wall -Wextra -Werror -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c staticTest.c*/
int	main(){
	int file;
	char	*temp;

	file = open("archivo.txt", O_RDONLY);
	temp = get_next_line(file);
	printf("RETURNEADO LA PRIEMRA VEZ: %s\n", temp);
	free(temp);
	get_next_line(file);
	printf("RETURNEADO LA SEGUNDA VEZ: %s\n", temp);
	free(temp);
	get_next_line(file);
	printf("RETURNEADO LA TERCERA VEZ: %s\n", temp);
	free(temp);
	close(file);
}
