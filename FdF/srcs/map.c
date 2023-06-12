/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:56:12 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/12 17:15:03 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

void	allocate_map_matrix(t_program* program) {
	char	*line;
	char	**elements;
	int		row;
	int		col;
	int		ptr;

	line = get_next_line(program->fd);
	elements = ft_split(line, ' ');
	col = ft_ptrlen(elements);
	row = 0;
	while (line != NULL) {
		row++;
		line = get_next_line(program->fd);
	}
	program->map.row = row;
	program->map.col = col;
	program->map.matrix = (int **)malloc(row * sizeof(int *));
	ptr = -1;
	while (ptr < row) 
		program->map.matrix[++ptr] = (int *)malloc(col * sizeof(int));
}

void	parse_map_file(t_program* program) {
	char	*line;
	char	**elements;
	int	rptr;
	int	cptr;

	rptr = -1;
	while (++rptr < program->map.row) {
		cptr = -1;
		line = get_next_line(program->fd);
		elements = ft_split(line, ' ');
		while (++cptr < program->map.col) {
			program->map.matrix[rptr][cptr] = ft_getnbr(elements[cptr]);
		}
	}
}

void	init_map(t_program* program) {
	program->fd = open(program->file_path, O_RDONLY);
	allocate_map_matrix(program);
	close(program->fd);
	program->fd = open(program->file_path, O_RDONLY);
	parse_map_file(program);
	close(program->fd);	
}