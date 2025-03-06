/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 23:29:23 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

static t_bool	validate_name(int argc, char **argv);
static int		part_2(t_args args);

int	main(int argc, char *argv[])
{
	void		*mlx;
	void		*win;
	t_assets	*assets;
	t_args		args;
	t_map		*map;

	if (validate_name(argc, argv) == FALSE)
		return (1);
	map = new_map(argv[1]);
	if (map == NULL)
		return (1);
	if (flood(map) == FALSE)
		return (destroy_map(map), 1);
	mlx = mlx_init();
	if (mlx == NULL)
		return (destroy_map(map), 0);
	assets = load_assets(mlx);
	win = mlx_new_window(mlx, map->width * assets->witdth,
			map->height * assets->height, "So_Long");
	args.mlx = mlx;
	args.win = win;
	args.map = map;
	args.assets = assets;
	return (part_2(args));
}

static int	part_2(t_args args)
{
	void		*mlx;
	void		*win;
	t_assets	*assets;
	t_map		*map;

	mlx = args.mlx;
	win = args.win;
	assets = args.assets;
	map = args.map;
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

static t_bool	validate_name(int argc, char **argv)
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

const char	*get_error_str(t_error status)
{
	if (status == ER_MALLOC)
		return ("Error de malloc");
	else if (status == ER_WIDTH)
		return ("El ancho del mapa no es consistente.");
	else if (status == ER_ONE_LINE)
		return ("El mapa debe tener al menos dos líneas");
	else if (status == ER_OPENFILE)
		return ("Error al abrir el archivo");
	else if (status == ER_BORDER)
		return ("El contorno del mapa no se ha cerrado correctamente");
	else if (status == ER_PLAYER)
		return ("Se han introducido dos posiciones de inicio");
	else if (status == ER_EXIT)
		return ("Se han establecido dos salidas");
	else if (status == ER_INVALID_CHAR)
		return ("Hay caracteres inválidos en el mapa.");
	else
		return ("Unknown error\n");
}

int	finish_win(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
