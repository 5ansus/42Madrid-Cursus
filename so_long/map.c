/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:28:02 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/06 23:48:45 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*_new_map(char *filename, t_error *status);
static t_bool	_read_file(int fd, t_map *m, t_list **lines, t_error *s);
static t_bool	_parse_matrix(t_map *m, t_list *l);
static t_bool	_loop_parse(t_map *m, t_list **lines, char *line, t_error *s);

t_map	*new_map(char *filename)
{
	t_error	status;
	t_map	*map;

	status = NO_ERROR;
	map = _new_map(filename, &status);
	if (status != NO_ERROR)
		return (ft_printf("Error: %s\n", get_error_str(status)), NULL);
	if (map->door.set == FALSE)
	{
		ft_printf("Error: No se ha establecido una salida\n");
		return (destroy_map(map), NULL);
	}
	if (map->player.set == FALSE)
	{
		ft_printf("Error: No se ha establecido una posición de inicio\n");
		return (destroy_map(map), NULL);
	}
	if (map->n_collectibles == 0)
	{
		ft_printf("Error: Debe haber al menos un item a recolectar\n");
		return (destroy_map(map), NULL);
	}
	return (map);
}

static t_map	*_new_map(char *filename, t_error *status)
{
	t_map	*map;
	t_list	*lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (*status = ER_OPENFILE, NULL);
	lines = NULL;
	map = (t_map *)malloc(sizeof(map[0]));
	if (map == NULL)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->n_collectibles = 0;
	map->player.set = FALSE;
	map->door.set = FALSE;
	map->status = status;
	if (_read_file(fd, map, &lines, status) == FALSE)
		return (close(fd), free(map), ft_lstclear(&lines, free), NULL);
	close(fd);
	map->width -= 1;
	if (_parse_matrix(map, lines) == FALSE)
		return (free(map), ft_lstclear(&lines, free), NULL);
	ft_lstclear(&lines, free);
	return (map);
}

static t_bool	_read_file(int fd, t_map *m, t_list **lines, t_error *s)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		_loop_parse(m, lines, line, s);
		if (*s != NO_ERROR)
			return (FALSE);
		line = ft_get_next_line(fd);
	}
	if (m->width == 0)
		return (*s = ER_ONE_LINE, FALSE);
	return (TRUE);
}

static t_bool	_parse_matrix(t_map *m, t_list *l)
{
	int		i;
	t_tile	**matrix;
	t_tile	*l_parsed;

	i = 0;
	matrix = malloc(m->height * sizeof(t_tile *));
	while (i < m->height)
	{
		if (i == 0 || i == (m->height - 1))
			l_parsed = _parse_line(l->content, m, TRUE, i);
		else
			l_parsed = _parse_line(l->content, m, FALSE, i);
		if (l_parsed == NULL)
		{
			while (i--)
				free(matrix[i]);
			free(matrix);
			return (FALSE);
		}
		matrix[i] = l_parsed;
		i++;
		l = l->next;
	}
	m->matrix = matrix;
	return (TRUE);
}

static t_bool	_loop_parse(t_map *m, t_list **lines, char *line, t_error *s)
{
	t_list	*new;

	if (m->height == 0)
	{
		m->height = 1;
		m->width = (int)ft_strlen(line);
		new = ft_lstnew(line);
		if (new == NULL)
			return (free(line), *s = ER_MALLOC, FALSE);
		ft_lstadd_back(lines, new);
	}
	else
	{
		m->height += 1;
		if (m->width != (int)ft_strlen(line))
			return (free(line), *s = ER_WIDTH, FALSE);
		new = ft_lstnew(line);
		if (new == NULL)
			return (free(line), *s = ER_MALLOC, FALSE);
		ft_lstadd_back(lines, new);
	}
	return (TRUE);
}
