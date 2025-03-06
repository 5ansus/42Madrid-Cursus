/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:30 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 18:17:22 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_assets *load_assets(void *mlx)
{
	t_assets *imgs;
	int w[N_ASSETS];
	int h[N_ASSETS];
	char *files[N_ASSETS] = {
		"sprites/coin.xpm", 
		"sprites/wall.xpm",
		"sprites/door_closed.xpm",
		"sprites/fill.xpm",
		"sprites/player.xpm",
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
	imgs->open = mlx_xpm_file_to_image(mlx, files[5], &w[5], &h[5]);
	if (imgs->coin == NULL || imgs->wall == NULL || imgs->door == NULL ||
			imgs->fill == NULL || imgs->player == NULL || imgs->open == NULL)
		return (destroy_assets(mlx, imgs), NULL);
	// ft_printf("Assets loaded\n");
	if (validate_assets(imgs, w, h) == FALSE)
		return (destroy_assets(mlx, imgs), NULL);
	// ft_printf("Assets loaded\n");
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
	while (i < N_ASSETS)
	{
		if (heights[i] != h || widths[i] != w)
			return (FALSE);
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
	if (imgs->open != NULL)
		mlx_destroy_image(mlx, imgs->open);
	free(imgs);
}

void initial_map_print(void *mlx, void *win, t_map *map, t_assets *imgs)
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