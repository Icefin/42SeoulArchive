/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by geshin            #+#    #+#             */
/*   Updated: 2023/09/14 13:02:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "object.h"

static void	free_array(char **ptr, int size)
{
	int	i;

	i = -1;
	while (++i <= size)
		free(ptr[i]);
	free(ptr);
}

static void	allocate_map_matrix(t_object *obj, int fd)
{
	char	*line;
	char	**elements;
	int		row;
	int		col;
	int		i;

	line = get_next_line(fd);
	elements = ft_split(line, ' ');
	col = ft_ptrlen(elements);
	free_array(elements, col);
	row = 0;
	while (line != NULL)
	{
		free(line);
		row++;
		line = get_next_line(fd);
	}
	free(line);
	obj->row = row;
	obj->col = col;
	obj->mesh = (int **)malloc(row * sizeof(int *));
	i = -1;
	while (++i < row)
		obj->mesh[i] = (int *)malloc(col * sizeof(int));
}

static void	parse_map_file(t_object *obj, int fd)
{
	char	*line;
	char	**elements;
	int		r;
	int		c;

	r = -1;
	while (++r < obj->row)
	{
		line = get_next_line(fd);
		elements = ft_split(line, ' ');
		free(line);
		c = -1;
		while (++c < obj->col)
			obj->mesh[r][c] = ft_atoi(elements[c]);
		free_array(elements, obj->col);
	}
}

void	init_object(t_object *obj, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	allocate_map_matrix(obj, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_map_file(obj, fd);
	close(fd);
}
