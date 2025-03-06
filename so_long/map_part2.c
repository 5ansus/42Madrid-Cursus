/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:59 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 22:41:56 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	aux(char *ln, t_map *m, t_tile *n_ln, t_point *p);
static t_bool	error_func(t_tile *new_line, t_error *s);

t_tile	*_parse_line(char *ln, t_map *m, t_bool bord, int y)
{
	int		x;
	t_tile	*new_line;
	t_point	p;

	x = 0;
	new_line = malloc(m->width * sizeof(t_tile));
	if (new_line == NULL)
		return (NULL);
	while (x < m->width)
	{
		p.x = x;
		p.y = y;
		if (bord == TRUE && (ln[x] != '1'))
			return (free(new_line), *(m->status) = ER_BORDER, NULL);
		else if (!bord && (x == 0 || x == (m->width - 1)) && (ln[x] != '1'))
			return (free(new_line), *(m->status) = ER_BORDER, NULL);
		else if (ln[x] == '0')
			new_line[x] = EMPTY;
		else if (ln[x] == '1')
			new_line[x] = WALL;
		else if (aux(ln, m, new_line, &p) == FALSE)
			return (NULL);
		x++;
	}
	return (new_line);
}

static void	collectible(t_map *m, t_point *p, t_tile *n_ln)
{
	n_ln[p->x] = COLLECTIBLE;
	m->n_collectibles += 1;
}

static t_bool	aux(char *ln, t_map *m, t_tile *n_ln, t_point *p)
{
	if (ln[p->x] == 'C')
		collectible(m, p, n_ln);
	else if (ln[p->x] == 'E')
	{
		n_ln[p->x] = EXIT;
		if (m->door.set == TRUE)
			return (free(n_ln), *(m->status) = ER_EXIT, FALSE);
		m->door.set = TRUE;
		m->door.x = p->x;
		m->door.y = p->y;
	}
	else if (ln[p->x] == 'P')
	{
		n_ln[p->x] = PLAYER;
		if (m->player.set == TRUE)
			return (free(n_ln), *(m->status) = ER_PLAYER, FALSE);
		m->player.set = TRUE;
		m->player.x = p->x;
		m->player.y = p->y;
	}
	else
		return (error_func(n_ln, m->status));
	return (TRUE);
}

static t_bool	error_func(t_tile *new_line, t_error *s)
{
	free(new_line);
	*s = ER_INVALID_CHAR;
	return (FALSE);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
}
