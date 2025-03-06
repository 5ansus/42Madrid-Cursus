/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:20:11 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 23:19:00 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_dir_move	get_dir(int keycode, void *param, t_args **p);
static void			get_n_pos(t_point *n_pos, t_point old_pos, t_dir_move dir);
static t_bool		move_valid(t_map *map, t_point new_pos, t_bool *open_door);
static void			mv(t_bool o_door, t_args *p, t_point old, t_point new_pos);

int	key_pressed(int keycode, void *param)
{
	static int	steps = 0;
	t_args		*p;
	t_point		points[2];
	t_dir_move	dir;
	t_bool		open_door;

	open_door = FALSE;
	dir = get_dir(keycode, param, &p);
	if (dir == NO_MOVE)
		return (0);
	points[0].x = p->map->player.x;
	points[0].y = p->map->player.y;
	get_n_pos(&points[1], points[0], dir);
	open_door = (p->map->n_collectibles == 0);
	if (!move_valid(p->map, points[1], &open_door))
		return (0);
	mv(open_door, p, points[0], points[1]);
	steps++;
	p->map->matrix[points[0].y][points[0].x] = EMPTY;
	p->map->matrix[points[1].y][points[1].x] = PLAYER;
	p->map->player.x = points[1].x;
	p->map->player.y = points[1].y;
	if (p->map->door.set == FALSE)
		return ((void) ft_printf("Steps: %d\n", steps), finish_win(p->mlx));
	return ((void) ft_printf("Steps: %d\n", steps), 0);
}

t_dir_move	get_dir(int keycode, void *param, t_args **p)
{
	*p = (t_args *)param;
	if (keycode == KEY_ESC)
		return (finish_win((*p)->mlx));
	if (keycode == KEY_UP || keycode == KEY_W)
		return (UP);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		return (DOWN);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		return (LEFT);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		return (RIGHT);
	return (NO_MOVE);
}

void	get_n_pos(t_point *n_pos, t_point old_pos, t_dir_move dir)
{
	n_pos->x = old_pos.x;
	n_pos->y = old_pos.y;
	if (dir == UP)
		n_pos->y -= 1;
	else if (dir == DOWN)
		n_pos->y += 1;
	else if (dir == LEFT)
		n_pos->x -= 1;
	else if (dir == RIGHT)
		n_pos->x += 1;
}

t_bool	move_valid(t_map *map, t_point new_pos, t_bool *open_door)
{
	t_tile	**m;

	m = map->matrix;
	if (m[new_pos.y][new_pos.x] == WALL)
		return (FALSE);
	if (m[new_pos.y][new_pos.x] == EXIT && *open_door == FALSE)
		return (FALSE);
	if (m[new_pos.y][new_pos.x] == COLLECTIBLE)
	{
		map->n_collectibles--;
		if (map->n_collectibles == 0)
			*open_door = TRUE;
	}
	if (m[new_pos.y][new_pos.x] == EXIT && *open_door == TRUE)
		map->door.set = FALSE;
	return (TRUE);
}

static void	mv(t_bool o_door, t_args *p, t_point old, t_point new_pos)
{
	void	*mlx;
	void	*win;
	t_point	c[3];

	mlx = p->mlx;
	win = p->win;
	c[0].x = old.x * p->assets->witdth;
	c[0].y = old.y * p->assets->height;
	c[1].x = new_pos.x * p->assets->witdth;
	c[1].y = new_pos.y * p->assets->height;
	c[2].x = p->map->door.x * p->assets->witdth;
	c[2].y = p->map->door.y * p->assets->height;
	if (o_door == TRUE)
		mlx_put_image_to_window(mlx, win, p->assets->open, c[2].x, c[2].y);
	mlx_put_image_to_window(mlx, win, p->assets->fill, c[0].x, c[0].y);
	mlx_put_image_to_window(mlx, win, p->assets->player, c[1].x, c[1].y);
}
