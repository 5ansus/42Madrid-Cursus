/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:28:02 by sanferna          #+#    #+#             */
/*   Updated: 2025/03/04 23:57:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <fcntl.h>

static t_map *_new_map(char *filename, t_error *status);
static t_bool _read_file(int fd, t_map *m, t_list **lines, t_error *s);
static t_bool _parse_matrix(t_map *m, t_list *l, t_error *s);
static t_tile *_parse_line(char *line, t_map *m, t_error *s, t_bool border, int y);

t_map *new_map(char *filename) {
	t_error status;
	t_map *map;

	status = NO_ERROR;
	map = _new_map(filename, &status);
	//TODO: Optimizar
	if (status != NO_ERROR){
		if (status == ER_MALLOC)
			ft_printf("Error de malloc\n");
		else if (status == ER_WIDTH)
			ft_printf("El ancho del mapa no es consistente.\n");
		else if (status == ER_ONE_LINE)
			ft_printf("El mapa debe tener al menos dos líneas\n");
		else if (status == ER_OPENFILE)
			ft_printf("Error al abrir el archivo\n");
		else if (status == ER_BORDER)
			ft_printf("El contorno del mapa no se ha cerrado correctamente\n");
		else if (status == ER_PLAYER)
			ft_printf("Se han introducido dos posiciones de inicio\n");
		else if (status == ER_EXIT)
			ft_printf("Se han establecido dos salidas\n");
		else if (status == ER_INVALID_CHAR)
			ft_printf("Hay caracteres inválidos en el mapa.\n");
		else
			ft_printf("Unknown error (%d)\n", status);
		return 0;
	}
	// TODO: Esto no va aquí
	if (map->door.set == FALSE)
	{
		ft_printf("ERROR: No se ha establecido una salida\n");
		destroy_map(map);
		return (NULL);
	}
	if (map->player.set == FALSE){
		ft_printf("ERROR: No se ha establecido una posición de inicio\n");
		destroy_map(map);
		return (NULL);
	}
	if (map->n_collectibles == 0){

		ft_printf("ERROR: Debe haber al menos un item a recolectar\n");
		destroy_map(map);
		return (NULL);
	}
	return (map);
}

// void printer(void *content) { ft_printf("%s\n", (char *)content); }
static t_map *_new_map(char *filename, t_error *status) {
	t_map *map;
	t_list *lines;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1) return (*status = ER_OPENFILE, NULL);
	lines = NULL;
	map = (t_map *)malloc(sizeof(map[0]));
	if (map == NULL) return (NULL);
	map->width = 0;
	map->height = 0;
	map->n_collectibles = 0;
	map->player.set = FALSE;
	map->door.set = FALSE;
	if (_read_file(fd, map, &lines, status) == FALSE)
		return (close(fd), free(map), ft_lstclear(&lines, free), NULL);
	close(fd);
	// ft_lstprint(&lines, printer);
	map->width -= 1;  // Hay que restar el "\n"
	if (_parse_matrix(map, lines, status) == FALSE)
		return (free(map), ft_lstclear(&lines, free), NULL);
	ft_lstclear(&lines, free);
	return (map);
}

static t_bool _read_file(int fd, t_map *m, t_list **lines, t_error *s) {
	char *line;
	t_list *new;

	line = ft_get_next_line(fd);
	while (line != NULL) {
		if (m->height == 0) {
			m->height = 1;
			m->width = (int)ft_strlen(line);
			new = ft_lstnew(line);
			if (new == NULL) return (free(line), *s = ER_MALLOC, FALSE);
			ft_lstadd_back(lines, new);
		} else {
			m->height += 1;
			if (m->width != (int)ft_strlen(line))
				return (free(line), *s = ER_WIDTH, FALSE);
			new = ft_lstnew(line);
			if (new == NULL) return (free(line), *s = ER_MALLOC, FALSE);
			ft_lstadd_back(lines, new);
		}
		line = ft_get_next_line(fd);
	}
	if (m->width == 0) return (*s = ER_ONE_LINE, FALSE);
	return (TRUE);
}

static t_bool _parse_matrix(t_map *m, t_list *l, t_error *s) {
	int i;
	t_tile **matrix;
	t_tile *l_parsed;

	i = 0;
	matrix = malloc(m->height * sizeof(t_tile *));
	while (i < m->height) {

		if (i == 0 || i == (m->height - 1))
			l_parsed = _parse_line(l->content, m, s, TRUE, i);
		else
			l_parsed = _parse_line(l->content, m, s, FALSE, i);
		if (l_parsed == NULL) {
			while (i--) free(matrix[i]);
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

static t_tile *_parse_line(char *line, t_map *m, t_error *s, t_bool border, int y) {
	int x;
	t_tile *new_line;

	x = 0;
	new_line = malloc(m->width * sizeof(t_tile));
	if (new_line == NULL) return (NULL);
	while (x < m->width) {
		if (border == TRUE && (line[x] != '1')) {
			free(new_line);
			*s = ER_BORDER;
			return (NULL);
		} else if (border == FALSE && (x == 0 || x == (m->width - 1)) && (line[x] != '1')) {
			free(new_line);
			*s = ER_BORDER;
			return (NULL);
		}
		else if (line[x] == '0')
			new_line[x] = EMPTY;
		else if (line[x] == '1')
			new_line[x] = WALL;
		else if (line[x] == 'C') {
			new_line[x] = COLLECTIBLE;
			m->n_collectibles += 1;
		} else if (line[x] == 'E') {
			new_line[x] = EXIT;
			if (m->door.set == TRUE) {
				free(new_line);
				*s = ER_EXIT;
				return (NULL);
			}
			m->door.set = TRUE;
			m->door.x = x;
			m->door.y = y;
		} else if (line[x] == 'P') {
			new_line[x] = PLAYER;
			if (m->player.set == TRUE) {
				free(new_line);
				*s = ER_PLAYER;
				return (NULL);
			}
			m->player.set = TRUE;
			m->player.x = x;
			m->player.y = y;
		}
		else {
			free(new_line);
			*s = ER_INVALID_CHAR;
			return (NULL);
		}

		x++;
	}
	return (new_line);
}

void destroy_map(t_map *map) {
	int i;
	i = 0;
	while (i < map->height) {
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
}

void print_map(t_map *map) {
	int i;
	int j;

	i = 0;
	ft_printf("Map:\n");
	ft_printf("\tWidth: %d\n", map->width);
	ft_printf("\tHeight: %d\n", map->height);
	ft_printf("\tCollectibles: %d\n", map->n_collectibles);
	ft_printf("\tMatrix:\n");
	while (i < map->height) {
		j = 0;
		ft_printf("\t\t");
		while (j < map->width) {
			if (map->matrix[i][j] == EMPTY)
				ft_printf("0");
			else if (map->matrix[i][j] == WALL)
				ft_printf("1");
			else if (map->matrix[i][j] == COLLECTIBLE)
				ft_printf("C");
			else if (map->matrix[i][j] == EXIT)
				ft_printf("E");
			else if (map->matrix[i][j] == PLAYER)
				ft_printf("P");
			else {
				ft_printf("?");
			}
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
