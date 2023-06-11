/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:56:12 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/11 20:27:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

static void	allocate_map_matrix(t_program* program) {
	char	*line;
	char	**row;
	int	col_len;
	int	row_len;
	int	ptr;

	line = get_next_line(program->fd);
	row = ft_split(line, " ");
	row_len = ft_strlen(row);
	while (line != NULL) {
		col_len++;
		line = get_next_line(program->fd);
	}
	program->map.row = row_len;
	program->map.col = col_len;
	program->map.matrix = (int**)malloc(col_len * sizeof(int*));
	ptr = -1;
	while (ptr < col_len) 
		program->map.matrix[++ptr] = (int*)malloc(row_len * sizeof(int));
}

static void	parse_map_file(t_program* program) {
	char	*line;
	char	**row;
	int	rptr;
	int	cptr;

	rptr = -1;
	while (++rptr < program->map.row) {
		cptr = -1;
		line = get_next_line(program->fd);
		row = ft_split(line, " ");
		while (++cptr < program->map.col) {
			program->map.matrix[rptr][cptr] = ft_getnbr(row[cptr]);
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