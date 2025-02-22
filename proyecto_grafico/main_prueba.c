/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2025/02/22 17:31:00 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
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

int main(void)
{
	void *mlx;
	void *win;
	t_image img;

	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	win = mlx_new_window(mlx, 800, 600, "Prueba");
	img.p = mlx_xpm_file_to_image(mlx, "sprites/coin.xpm", &img.witdth, &img.height);
	mlx_put_image_to_window(mlx, win, img.p, 0, 0);
	mlx_hook(win, 17, 1<<17, finish_win, mlx);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
