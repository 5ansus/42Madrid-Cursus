/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:30 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 21:48:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_initial_loop(t_args *args, int x, int y);

t_assets	*load_assets(void *mlx)
{
	t_assets	*imgs;
	int			w[N_ASSETS];
	int			h[N_ASSETS];
	const char	*file[N_ASSETS] = {"sprites/coin.xpm", "sprites/wall.xpm",
		"sprites/door_closed.xpm", "sprites/fill.xpm", "sprites/player.xpm",
		"sprites/door_open.xpm"};

	imgs = malloc(sizeof(t_assets));
	if (imgs == NULL)
		return (NULL);
	imgs->coin = mlx_xpm_file_to_image(mlx, (char *) file[0], &w[0], &h[0]);
	imgs->wall = mlx_xpm_file_to_image(mlx, (char *) file[1], &w[1], &h[1]);
	imgs->door = mlx_xpm_file_to_image(mlx, (char *) file[2], &w[2], &h[2]);
	imgs->fill = mlx_xpm_file_to_image(mlx, (char *) file[3], &w[3], &h[3]);
	imgs->player = mlx_xpm_file_to_image(mlx, (char *) file[4], &w[4], &h[4]);
	imgs->open = mlx_xpm_file_to_image(mlx, (char *) file[5], &w[5], &h[5]);
	if (imgs->coin == NULL || imgs->wall == NULL || imgs->door == NULL
		|| imgs->fill == NULL || imgs->player == NULL || imgs->open == NULL)
		return (destroy_assets(mlx, imgs), NULL);
	if (validate_assets(imgs, w, h) == FALSE)
		return (destroy_assets(mlx, imgs), NULL);
	return (imgs);
}

t_bool	validate_assets(t_assets *assets, int *widths, int *heights)
{
	int	i;
	int	w;
	int	h;

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

void	destroy_assets(void *mlx, t_assets *imgs)
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

void	initial_map_print(t_args *args)
{
	int			x;
	int			y;
	t_map		*map;

	y = 0;
	map = args->map;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			_initial_loop(args, x, y);
			x++;
		}
		y++;
	}
}

static void	_initial_loop(t_args *args, int x, int y)
{
	void		*img;
	void		*mlx;
	void		*win;
	t_assets	*assets;
	t_tile		**m;

	mlx = args->mlx;
	win = args->win;
	assets = args->assets;
	img = NULL;
	m = args->map->matrix;
	if (m[y][x] == WALL)
		img = assets->wall;
	else if (m[y][x] == COLLECTIBLE)
		img = assets->coin;
	else if (m[y][x] == EXIT)
		img = assets->door;
	else if (m[y][x] == EMPTY)
		img = assets->fill;
	else if (m[y][x] == PLAYER)
		img = assets->player;
	x = x * assets->witdth;
	y = y * assets->height;
	mlx_put_image_to_window(mlx, win, img, x, y);
}
