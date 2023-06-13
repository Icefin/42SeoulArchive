/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:56:12 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/13 12:30:54 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "map.h"

static void	allocate_map_matrix(t_map* map, int fd) {
	char	*line;
	char	**elements;
	int		row;
	int		col;
	int		ptr;

	line = get_next_line(fd);
	elements = ft_split(line, ' ');
	col = ft_ptrlen(elements);
	row = 0;
	while (line != NULL) {
		row++;
		line = get_next_line(fd);
	}
	map->row = row;
	map->col = col;
	map->matrix = (int **)malloc(row * sizeof(int *));
	ptr = -1;
	while (ptr < row) 
		map->matrix[++ptr] = (int *)malloc(col * sizeof(int));
}

static void	parse_map_file(t_map* map, int fd) {
	char	*line;
	char	**elements;
	int	rptr;
	int	cptr;

	rptr = -1;
	while (++rptr < map->row) {
		cptr = -1;
		line = get_next_line(fd);
		elements = ft_split(line, ' ');
		while (++cptr < map->col) {
			map->matrix[rptr][cptr] = ft_getnbr(elements[cptr]);
		}
	}
}

void	init_map(t_map* map, char* path) {
	int fd;
	fd = open(path, O_RDONLY);
	allocate_map_matrix(map, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_map_file(map, fd);
	close(fd);	
}