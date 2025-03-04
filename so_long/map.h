/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:28:10 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/04 23:55:40 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H
#include "libft/libft.h"

typedef enum e_bool { FALSE = 0, TRUE = 1 } t_bool;

typedef enum e_tide {
	EMPTY = 0,
	WALL = 1,
	COLLECTIBLE = 2,
	EXIT = 3,
	PLAYER = 4
} t_tile;

typedef enum e_error {

	ER_MALLOC = -1,
	NO_ERROR = 0,
	ER_WIDTH,
	ER_BORDER,
	ER_PLAYER,
	ER_EXIT,
	ER_ONE_LINE,
	ER_OPENFILE,
	ER_INVALID_CHAR
} t_error;

typedef struct s_point {
	t_bool set;
	int x;
	int y;
} t_point;

typedef struct s_map {
	int width;
	int height;
	int n_collectibles;
	t_point player;
	t_point door;
	t_tile **matrix;
} t_map;

t_map *new_map(char *filename);
void destroy_map(t_map *map);
void print_map(t_map *map);
#endif
