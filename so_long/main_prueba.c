/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/05 00:11:45 by sanferna         ###   ########.fr       */
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

typedef struct s_image
{

	void *p;
	int height;
	int witdth;
} t_image;

typedef struct s_assets
{

	t_image *coin;
	t_image *player;
	t_image *wall;
	t_image *door;
	t_image *fill;
} t_assets;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_CLOSE = 17,
} t_event;

typedef struct s_args
{
	t_map *map;
	int *x;
	int *y;
	void *mlx;
	void *win;
	t_assets *assets;
} t_args;

int move_player(int keycode, void *param)
{
	t_args *p = (t_args *)param;
	t_map *map = p->map;
	int x = *p->x;
	int y = *p->y;

	int player_x = map->player.x;
	int player_y = map->player.y;

	void *mlx = p->mlx;
	void *win = p->win;
	t_assets *assets = p->assets;

	mlx_put_image_to_window(mlx, win, (*assets).fill.p, player_x * (*assets).fill.witdth, player_y * (*assets).fill.height);
	mlx_put_image_to_window(mlx, win, (*assets).player.p,(player_x+1) * (*assets).player.witdth, player_y * (*assets).player.height);

	map->matrix[player_y][player_x] = EMPTY;
	map->matrix[player_y][player_x + 1] = PLAYER;
	map->player.x = player_x + 1;
	print_map(map);
	return 0;
}

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
	assets.door.p = mlx_xpm_file_to_image(mlx, "sprites/door_closed.xpm", &assets.door.witdth, &assets.door.height);
	assets.fill.p = mlx_xpm_file_to_image(mlx, "sprites/fill.xpm", &assets.fill.witdth, &assets.fill.height);
	win = mlx_new_window(mlx, map->width * assets.wall.witdth, map->height * assets.wall.height, "Prueba");
	// mlx_put_image_to_window(mlx, win, assets.coin.p, 0, 0);
	// mlx_put_image_to_window(mlx, win, assets.coin.p, 64, 64);
	print_map(map);
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			if (map->matrix[y][x] == WALL)
				mlx_put_image_to_window(mlx, win, assets.wall.p, x * assets.wall.witdth, y * assets.wall.height);
			else if (map->matrix[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(mlx, win, assets.coin.p, x * assets.coin.witdth, y * assets.coin.height);
			else if (map->matrix[y][x] == PLAYER)
				mlx_put_image_to_window(mlx, win, assets.player.p, x * assets.player.witdth, y * assets.player.height);
			else if (map->matrix[y][x] == EXIT)
				mlx_put_image_to_window(mlx, win, assets.door.p, x * assets.door.witdth, y * assets.door.height);
			else if (map->matrix[y][x] == EMPTY)
				mlx_put_image_to_window(mlx, win, assets.fill.p, x * assets.fill.witdth, y * assets.fill.height);
		}
	}

	mlx_hook(win, 17, 1 << 17, finish_win, mlx);
	int a = 64;
	int b = 64;

	t_args args = {map, &a, &b, mlx, win, &assets};
	
	mlx_hook(win, 2, 1L<<0, move_player, &args);
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


t_assets *load_assets(void *mlx)
{
	t_assets *imgs;
	imgs = malloc(sizeof(t_assets));
	if (imgs == NULL)
		return (NULL);
	imgs->coin->p = mlx_xpm_file_to_image(mlx, "sprites/coin.xpm", &imgs->coin->witdth, &imgs->coin->height);
	imgs->player->p = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &imgs->player->witdth, &imgs->player->height);
	imgs->wall->p = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &imgs->wall->witdth, &imgs->wall->height);
	imgs->door->p = mlx_xpm_file_to_image(mlx, "sprites/door_closed.xpm", &imgs->door->witdth, &imgs->door->height);
	imgs->fill->p = mlx_xpm_file_to_image(mlx, "sprites/fill.xpm", &imgs->fill->witdth, &imgs->fill->height);
	if (imgs->coin->p == NULL || imgs->player->p == NULL || imgs->wall->p == NULL || imgs->door->p == NULL || imgs->fill->p == NULL)
	{
		free(imgs);
		return (NULL);
	}
	return (imgs);
}