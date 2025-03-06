/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/05 00:44:47 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>


typedef enum e_keys
{
	UNKNOWN = 0,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	UP = 65362,
	DOWN = 65364, 
	LEFT = 65361,
	RIGHT = 65363,
	ESC = 65307
} t_keys;

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
	void *player;
	void *coin;
	void *wall;
	void *door;
	void *fill;
	int height;
	int witdth;
} t_assets;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	// ON_KEYUP = 3,
	ON_CLOSE = 17,
} t_event;

typedef struct s_args
{
	void *mlx;
	void *win;
	t_map *map;
	t_assets *assets;
} t_args;

int move_player(int keycode, void *param)
{
	t_args *p = (t_args *)param;
	t_map *map = p->map;
	void *mlx = p->mlx;
	void *win = p->win;
	t_assets *imgs = p->assets;
	t_tile **matrix = map->matrix;

	int *x = &(map->player.x);
	int *y = &(map->player.y);


	ft_printf("Keycode: %d\n", keycode);

	if (matrix[*y][*x + 1] == WALL)
		return 0;
	mlx_put_image_to_window(mlx, win, imgs->player, (*x + 1) * imgs->witdth, *y * imgs->height);
	mlx_put_image_to_window(mlx, win, imgs->fill, *x * imgs->witdth, *y * imgs->height);


	ft_printf("%d -- %d\n", *x, *y);

	matrix[*y][*x] = EMPTY;
	matrix[*y][*x + 1] = PLAYER;
	*x += 1; 
	print_map(map);

	return 0;
}

t_assets *load_assets(void *mlx);
t_bool validate_assets(t_assets *assets, int *widths, int *heights);
void destroy_assets(void *mlx, t_assets *imgs);
void put_map(void *mlx, void *win, t_map *map, t_assets *imgs);

int main(void)
{
	void *mlx;
	void *win;
	t_assets *assets;
	t_map *map;

	map = new_map("maps/simple.ber");
	if (map == NULL)
		return (0);

	mlx = mlx_init();
	if (mlx == NULL)
		return (destroy_map(map), 0);
	assets = load_assets(mlx);
	print_map(map);
	win = mlx_new_window(mlx, map->width * assets->witdth, map->height * assets->height, "Prueba");

	put_map(mlx, win, map, assets);

	mlx_hook(win, 17, 1 << 17, finish_win, mlx);

	t_args args = {mlx, win, map, assets};
	
	mlx_hook(win, 2, 1L<<0, move_player, &args);
	mlx_loop(mlx);
	destroy_assets(mlx, assets);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	destroy_map(map);
	return (0);
}


t_assets *load_assets(void *mlx)
{
	t_assets *imgs;
	int w[5];
	int h[5];
	char *files[5] = {
		"sprites/coin.xpm",
		"sprites/wall.xpm",
		"sprites/door_closed.xpm",
		"sprites/fill.xpm",
		"sprites/player.xpm"
		"sprites/door_open.xpm"
	};

	imgs = malloc(sizeof(t_assets));
	if (imgs == NULL)
		return (NULL);

	imgs->coin = mlx_xpm_file_to_image(mlx, files[0], &w[0], &h[0]);
	imgs->wall = mlx_xpm_file_to_image(mlx, files[1], &w[1], &h[1]);
	imgs->door = mlx_xpm_file_to_image(mlx, files[2], &w[2], &h[2]);
	imgs->fill = mlx_xpm_file_to_image(mlx, files[3], &w[3], &h[3]);
	imgs->player = mlx_xpm_file_to_image(mlx, files[4], &w[4], &h[4]);
	imgs->player = mlx_xpm_file_to_image(mlx, files[4], &w[4], &h[4]);
	if (imgs->coin == NULL || imgs->wall == NULL || imgs->door == NULL ||
			imgs->fill == NULL || imgs->player == NULL)
		return (destroy_assets(mlx, imgs), NULL);
	if (validate_assets(imgs, w, h) == FALSE)
		return (destroy_assets(mlx, imgs), NULL);
	return (imgs);
}


t_bool validate_assets(t_assets *assets, int *widths, int *heights)
{
	int i;
	int w;
	int h;

	h = heights[0];
	w = widths[0];
	i = 1;
	while (i < 5)
	{
		if (heights[i] != h || widths[i] != w)
		{
			free(assets);
			return (FALSE);
		}
		i++;
	}
	assets->height = h;
	assets->witdth = w;
	return (TRUE);
}

void destroy_assets(void *mlx, t_assets *imgs)
{
	if (imgs == NULL)
		return ;
	if (imgs->coin != NULL)
		mlx_destroy_image(mlx, imgs->coin);
	if (imgs->wall != NULL)
		mlx_destroy_image(mlx, imgs->wall);
	if (imgs->door != NULL)
		mlx_destroy_image(mlx, imgs->door);
	if (imgs->fill != NULL)
		mlx_destroy_image(mlx, imgs->fill);
	if (imgs->player != NULL)
		mlx_destroy_image(mlx, imgs->player);
	free(imgs);
}

void put_map(void *mlx, void *win, t_map *map, t_assets *imgs)
{
	int x;
	int y;
	t_tile **m;

	y = 0;
	m = map->matrix;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (m[y][x] == WALL)
				mlx_put_image_to_window(mlx, win, imgs->wall, x * imgs->witdth, y * imgs->height);
			else if (m[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(mlx, win, imgs->coin, x * imgs->witdth, y * imgs->height);
			else if (m[y][x] == PLAYER)
				mlx_put_image_to_window(mlx, win, imgs->player, x * imgs->witdth, y * imgs->height);
			else if (m[y][x] == EXIT)
				mlx_put_image_to_window(mlx, win, imgs->door, x * imgs->witdth, y * imgs->height);
			else if (m[y][x] == EMPTY)
				mlx_put_image_to_window(mlx, win, imgs->fill, x * imgs->witdth, y * imgs->height);
			x++;
		}
		y++;
	}
}