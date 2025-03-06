/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 21:33:55 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

t_bool validate_args(int argc, char **argv);

int main(int argc, char *argv[])
{
	void *mlx;
	void *win;
	t_assets *assets;
	t_args args;
	t_map *map;

	if (validate_args(argc, argv) == FALSE)
		return (1);
	map = new_map(argv[1]);
	if (map == NULL)
		return (1);

	if (flood(map) == FALSE)
		return (destroy_map(map), 1);
	ft_printf("Mapa válido\n");
	mlx = mlx_init();
	if (mlx == NULL)
		return (destroy_map(map), 0);
	assets = load_assets(mlx);
	win = mlx_new_window(mlx, map->width * assets->witdth, map->height * assets->height, "So_Long");
	args.mlx = mlx;
	args.win = win;
	args.map = map;
	args.assets = assets;
	initial_map_print(&args);

	mlx_hook(win, 17, 1 << 17, finish_win, mlx);


	mlx_hook(win, 2, 1L << 0, key_pressed, &args);
	mlx_loop(mlx);
	destroy_assets(mlx, assets);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	destroy_map(map);
	return (0);
}

t_bool validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: Se necesita el nombre de un mapa.\n");
		return (FALSE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: El fichero ha de tener de extensión '.ber'\n");
		return (FALSE);
	}
	return (TRUE);
}
