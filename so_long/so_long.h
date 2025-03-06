/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:17 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 22:48:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

#define MAX_HEIGHT 30
#define MAX_WIDTH 60
#define N_ASSETS 6

typedef enum e_bool
{
	FALSE = 0, 
	TRUE = 1
} t_bool;

typedef enum e_tide {
	EMPTY = 0,
	WALL = 1,
	COLLECTIBLE = 2,
	EXIT = 3,
	PLAYER = 4,
	FILLED = 5
} t_tile;

typedef enum e_keys
{
	KEY_UNKNOWN = 0,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_DOWN = 65364, 
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307
} t_keys;

typedef enum e_dir_move
{
	NO_MOVE = -1,
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
} t_dir_move;

typedef enum e_error {

	ER_MALLOC = -1,
	NO_ERROR = 0,
	ER_WIDTH,
	ER_BORDER,
	ER_PLAYER,
	ER_EXIT,
	ER_ONE_LINE,
	ER_OPENFILE,
	ER_INVALID_CHAR
} t_error;

typedef struct s_point {
	t_bool set;
	int x;
	int y;
} t_point;

typedef struct s_map {
	int width;
	int height;
	int n_collectibles;
	t_point player;
	t_point door;
	t_tile **matrix;
	t_error *status;
} t_map;

typedef struct s_assets
{
	void *player;
	void *coin;
	void *wall;
	void *door;
	void *fill;
	void *open;
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

t_map *new_map(char *filename);
void destroy_map(t_map *map);
void print_map(t_map *map);


t_assets *load_assets(void *mlx);
t_bool validate_assets(t_assets *assets, int *widths, int *heights);
void destroy_assets(void *mlx, t_assets *imgs);
void	initial_map_print(t_args *args);

int finish_win(void *mlx);
int key_pressed(int keycode, void *param);

t_bool flood(t_map *map);
t_tile *_parse_line(char *ln, t_map *m, t_bool bord, int y);
const char	*get_error_str(t_error status);

#endif