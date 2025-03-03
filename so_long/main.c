/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:24:03 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/02 18:59:10 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "map.h"

int main() {
	t_map *map;

	map = new_map("maps/map.ber");
	if (map == NULL) {
		return (1);
	}
	else {
		print_map(map);
		destroy_map(map);
	}
	return (0);
}
