/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticTest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:34:23 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/09 15:50:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(){
	int file;
	char	*temp;

	file = open("archivo.txt", O_RDONLY);
	temp = get_next_line(file);
	printf("RETURNEADO LA PRIEMRA VEZ\n%s\n", temp);
	free(temp);
	get_next_line(file);
	printf("RETURNEADO LA SEGUNDA VEZ\n%s\n", temp);
	free(temp);
	get_next_line(file);
	printf("RETURNEADO LA TERCERA VEZ\n%s\n", temp);
	free(temp);
	close(file);
}
