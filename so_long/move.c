/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:20:11 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 19:10:59 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_dir_move get_dir(int keycode);
void get_new_pos(t_point *new_pos, t_point old_pos, t_dir_move dir);
t_bool move_valid(t_map *map, t_bool e_open, t_point new_pos, t_bool *open_door);

int finish_win(void *mlx)
{
	mlx_loop_end(mlx);
	return (26);
}

int key_pressed(int keycode, void *param)
{
	t_args *p = (t_args *)param;
	void *mlx = p->mlx;
	void *win = p->win;
	t_point old;
	t_point new_pos;
	t_dir_move dir;
	t_map *map = p->map;
	t_tile **matrix = map->matrix;
	t_bool open_door;
	static int steps = 0;

	open_door = FALSE;
	old.x = p->map->player.x;
	old.y = p->map->player.y;
	// ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		return finish_win(mlx);
	dir = get_dir(keycode);
	if (dir == NO_MOVE)
		return 0;
	get_new_pos(&new_pos, old, dir);
	if (!move_valid(p->map, (map->n_collectibles == 0), new_pos, &open_door))
		return 0;
	if (open_door)
		mlx_put_image_to_window(mlx, win, p->assets->open, p->map->door.x * p->assets->witdth, p->map->door.y * p->assets->height);

	mlx_put_image_to_window(mlx, win, p->assets->fill, old.x * p->assets->witdth, old.y * p->assets->height);
	mlx_put_image_to_window(mlx, win, p->assets->player, new_pos.x * p->assets->witdth, new_pos.y * p->assets->height);

	steps++;
	ft_printf("Steps: %d\n", steps);
	matrix[old.y][old.x] = EMPTY;
	matrix[new_pos.y][new_pos.x] = PLAYER;
	p->map->player.x = new_pos.x;
	p->map->player.y = new_pos.y;

	if(map->door.set == FALSE)
		return finish_win(mlx);

	return 0;
}

t_dir_move get_dir(int keycode)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		return UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		return DOWN;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		return LEFT;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		return RIGHT;
	return -1;
}

void get_new_pos(t_point *new_pos, t_point old_pos, t_dir_move dir)
{
	new_pos->x = old_pos.x;
	new_pos->y = old_pos.y;
	if (dir == UP)
		new_pos->y -= 1;
	else if (dir == DOWN)
		new_pos->y += 1;
	else if (dir == LEFT)
		new_pos->x -= 1;
	else if (dir == RIGHT)
		new_pos->x += 1;
}


t_bool move_valid(t_map *map, t_bool e_open, t_point new_pos, t_bool *open_door)
{
	t_tile **m = map->matrix;

	if (m[new_pos.y][new_pos.x] == WALL)
		return FALSE;
	if (m[new_pos.y][new_pos.x] == EXIT && !e_open)
		return FALSE;

	if (m[new_pos.y][new_pos.x] == COLLECTIBLE)
	{
		map->n_collectibles--;
		if (map->n_collectibles == 0)
			*open_door = TRUE;
	}
	if (m[new_pos.y][new_pos.x] == EXIT && e_open)
		map->door.set = FALSE;
	return TRUE;
}