/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 13:50:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "object.h"

static void	allocate_map_matrix(t_object *obj, int fd)
{
	char	*line;
	char	**elements;
	int		row;
	int		col;
	int		ptr;

	line = get_next_line(fd);
	elements = ft_split(line, ' ');
	col = ft_ptrlen(elements);
	row = 0;
	while (line != NULL)
	{
		row++;
		line = get_next_line(fd);
	}
	obj->row = row;
	obj->col = col;
	obj->mesh = (int **)malloc(row * sizeof(int *));
	ptr = -1;
	while (ptr < row)
		obj->mesh[++ptr] = (int *)malloc(col * sizeof(int));
}

static void	parse_map_file(t_object *obj, int fd)
{
	char	*line;
	char	**elements;
	int		rptr;
	int		cptr;

	rptr = -1;
	while (++rptr < obj->row)
	{
		cptr = -1;
		line = get_next_line(fd);
		elements = ft_split(line, ' ');
		while (++cptr < obj->col)
			obj->mesh[rptr][cptr] = ft_atoi(elements[cptr]);
	}
}

void	init_object(t_object *obj, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	allocate_map_matrix(obj, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_map_file(obj, fd);
	close(fd);
}
