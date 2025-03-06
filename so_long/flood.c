/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:53:25 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:32 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void paint(t_map *map, t_tile **matrix, int y, int x);
t_bool _flood_aux(t_map *map, t_point player, t_tile **matrix);
t_bool _check_flood(t_map *map, t_tile **matrix);
t_bool _copy_matrix(t_map *m, t_tile **matrix);

t_bool flood(t_map *map)
{
	t_tile **matrix;
	t_bool ret;
	int i;

	if (map->width > MAX_WIDTH || map->height > MAX_HEIGHT)
	{
		ft_printf("Error: Mapa demasiado grande.\n");
		return (FALSE);
	}
	matrix = (t_tile **)malloc(map->height * sizeof(t_tile *));
	if (matrix == NULL)
		return ((void)ft_printf("Error: Malloc en flood\n"), FALSE);
	if (_copy_matrix(map, matrix) == FALSE)
	{
		free(matrix);
		return (FALSE);
	}
	ret = _flood_aux(map, map->player, matrix);
	i = 0;
	while (i < map->height)
		free(matrix[i++]);
	free(matrix);
	return (ret);
}

t_bool _copy_matrix(t_map *m, t_tile **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < m->height)
	{
		matrix[i] = (t_tile *)malloc(m->width * sizeof(t_tile));
		if (matrix[i] == NULL)
		{
			ft_printf("Error: No se pudo reservar memoria para el flood.\n");
			while (i > 0)
				free(matrix[--i]);
			return (FALSE);
		}
		j = 0;
		while (j < m->width)
		{
			matrix[i][j] = m->matrix[i][j];
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool _flood_aux(t_map *map, t_point player, t_tile **matrix)
{
	paint(map, matrix, player.y, player.x);
	if (_check_flood(map, matrix) == FALSE)
	{
		ft_printf("Error: No se puede acceder a todas las monedas y/o salida\n");
		return (FALSE);
	}
	return (TRUE);
}

void paint(t_map *map, t_tile **matrix, int y, int x)
{
	if (matrix[y][x] == EXIT)
	{
		matrix[y][x] = FILLED;
		return;
	}
	if (matrix[y][x] == WALL || matrix[y][x] == FILLED)
		return;
	matrix[y][x] = FILLED;
	if (y > 0)
		paint(map, matrix, y - 1, x);
	if (y < map->height - 1)
		paint(map, matrix, y + 1, x);
	if (x > 0)
		paint(map, matrix, y, x - 1);
	if (x < map->width - 1)
		paint(map, matrix, y, x + 1);
}

t_bool _check_flood(t_map *map, t_tile **matrix)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (matrix[y][x] == COLLECTIBLE)
				return (FALSE);
			x++;
		}
		y++;
	}
	if (matrix[map->door.y][map->door.x] != FILLED)
		return (FALSE);
	return (TRUE);
}
