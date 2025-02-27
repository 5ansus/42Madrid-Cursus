/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:28:02 by sanferna          #+#    #+#             */
/*   Updated: 2025/02/27 22:28:02 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <fcntl.h>

t_map *new_map(char *filename) {
	t_error status;
	t_map *map;

	map = _new_map(filename, &status);
	if (status == ER_MALLOC)
		printf();
	else if (status == ER_WIDTH)
		printf();
	else if (status == ER_ONE_LINE)
		printf();
	else if (status == ER_OPENFILE)
		printf();
	return (map);
}

t_map *_new_map(char *filename, t_error *status) {
	t_map *map;
	t_list *lines;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1) return (*status = ER_OPENFILE, NULL);
	lines = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL) return (NULL);
	map->width = 0;
	map->height = 0;
	map->exit_set = FALSE;
	map->player_set = FALSE;
	if (_read_file(filename, map, lines, status) == FALSE)
		return (close(fd), free(map), ft_lstclear(lines, free), NULL);
	close(fd);
	map->width -= 1;  // Hay que restar el "\n"
	if (_parse_matrix(map, lines, status) == FALSE)
		return (free(map), ft_lstclear(lines, free), NULL);
}

t_bool _read_file(int fd, t_map *m, t_list **lines, t_error *s) {
	char *line;
	t_list *new;
	int i;

	line = ft_get_next_line(fd);
	while (line != NULL) {
		if (m->height == 0) {
			m->height = 1;
			m->width = ft_get_next_line(line);
		} else {
			m->height += 1;
			if (m->width != ft_get_next_line(line))
				return (free(line), *s = ER_WIDTH, FALSE);
			new = ft_lstnew(line);
			if (new == NULL) return (free(line), *s = ER_MALLOC, FALSE);
			ft_lstadd_back(lines, line);
		}
	}
	if (m->width == 0) return (*s = ER_ONE_LINE, FALSE);
	return (*s = NO_ERROR, TRUE);
}

t_bool _parse_matrix(t_map *m, t_list *l, t_error *s) {
	int i;
	t_tile **matrix;
	t_tile *l_parsed;

	i = 0;
	matrix = malloc(sizeof(t_tile[0]) * m->height);
	while (i < m->height) {
		if (i == 0 || i == (m->height - 1))
			l_parsed = _parse_line(l->content, m, TRUE);
		else
			l_parsed = _parse_line(l->content, m, FALSE);
		if (l_parsed == NULL) {
			while (i--) free(matrix[i]);
			free(matrix);
		}
		matrix[i] = l_parsed;
		i++;
	}
}

t_tile *_parse_line(char *line, t_map *m, t_bool border) {
	int i;
	t_tile *new_line;

	i = 0;
	new_line = malloc(sizeof(t_tile) * m->width);
	if (new_line == NULL) return (NULL);
	while (i < m->width) {
		if (line[i] == "0")
			new_line[i] = EMPTY;
		else if (line[i] == "1")
			new_line[i] = WALL;
		else if (line[i] == "C") {
			new_line[i] = COLLECTIBLE;
			m->n_collectibles += 1;
		} else if (line[i] == "E") {
			new_line[i] = EXIT;
			if (m->exit_set == TRUE)
				;
			// Lanzar errror
		} else if (line[i] == "P") {
			new_line[i] = PLAYER;
			if (m->player_set == TRUE)
				;
			// Lanzar errror
		}
	}
}
