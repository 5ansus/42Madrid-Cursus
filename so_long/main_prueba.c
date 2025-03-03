/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/03 17:26:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

int finish_win(void *mlx)
{
	mlx_loop_end(mlx);
	return (26);
}

typedef struct s_image {

	void	*p;
	int		height;
	int		witdth;
} t_image;

typedef struct s_assets {

	t_image	coin;
	t_image	player;
	t_image	wall;
	t_image	door;
} t_assets;

int main(void)
{
	void *mlx;
	void *win;
	t_assets assets;
	t_map *map;

	map = new_map("maps/simple.ber");
	if (map == NULL)
		return (0);


	mlx = mlx_init();
	if (mlx == NULL)
		return (destroy_map(map), 0);
	assets.coin.p = mlx_xpm_file_to_image(mlx, "sprites/coin.xpm", &assets.coin.witdth, &assets.coin.height);
	assets.player.p = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &assets.player.witdth, &assets.player.height);
	assets.wall.p = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &assets.wall.witdth, &assets.wall.height);
	assets.door.p = mlx_xpm_file_to_image(mlx, "sprites/door.xpm", &assets.door.witdth, &assets.door.height);
	win = mlx_new_window(mlx, map->width * assets.wall.witdth, map->height * assets.wall.height, "Prueba");
	// mlx_put_image_to_window(mlx, win, assets.coin.p, 0, 0);
	// mlx_put_image_to_window(mlx, win, assets.coin.p, 64, 64);
	print_map(map);
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x< map->width; x++)
		{
			if (map->matrix[y][x] == WALL)
				mlx_put_image_to_window(mlx, win, assets.wall.p, x * assets.wall.witdth, y * assets.wall.height);
			else if (map->matrix[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(mlx, win, assets.coin.p, x * assets.coin.witdth, y * assets.coin.height);
			else if (map->matrix[y][x] == PLAYER)
				mlx_put_image_to_window(mlx, win, assets.player.p, x * assets.player.witdth, y * assets.player.height);
			else if (map->matrix[y][x] == EXIT)
				mlx_put_image_to_window(mlx, win, assets.door.p, x * assets.door.witdth, y * assets.door.height);
		}
	}
	
	mlx_hook(win, 17, 1<<17, finish_win, mlx);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, assets.coin.p);
	mlx_destroy_image(mlx, assets.player.p);
	mlx_destroy_image(mlx, assets.wall.p);
	mlx_destroy_image(mlx, assets.door.p);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	destroy_map(map);
	return (0);
}

	// mlx = mlx_init();
	// if (mlx == NULL)
	// 	return (0);
	// win = mlx_new_window(mlx, 800, 600, "Prueba");
	// img.p = mlx_xpm_file_to_image(mlx, "sprites/coin.xpm", &img.witdth, &img.height);
	// mlx_put_image_to_window(mlx, win, img.p, 0, 0);
	// mlx_hook(win, 17, 1<<17, finish_win, mlx);
	// mlx_loop(mlx);
	// mlx_destroy_window(mlx, win);
	// mlx_destroy_display(mlx);
	// free(mlx);