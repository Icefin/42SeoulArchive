/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:27:18 by singeonho         #+#    #+#             */
/*   Updated: 2023/08/30 23:31:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "object.h"

static void	allocate_mesh_memory(t_object* obj, int* outrow, int* outcol, int fd)
{
	char	*line;
	char	**elements;
	int		numrow;
	int		numcol;

	line = get_next_line(fd);
	elements = ft_split(line, ' ');
	numcol = ft_ptrlen(elements);
	numrow = 0;
	while (line != NULL)
	{
		numrow++;
		line = get_next_line(fd);
	}
	*outrow = numrow;
	*outcol = numcol;
	obj->numvertices = numcol * numrow;
	obj->vertices = (t_vec4 *)malloc(obj->numvertices * sizeof(t_vec4));
}

static void	parse_fdf_file(t_object* obj, int numrow, int numcol, int fd)
{
	char	*line;
	char	**elements;
	int		rptr;
	int		cptr;

	rptr = -1;
	while (++rptr < numrow)
	{
		cptr = -1;
		line = get_next_line(fd);
		elements = ft_split(line, ' ');
		while (++cptr < numcol)
			obj->vertices[rptr + cptr] = make_vec4(cptr, ft_getnbr(elements[cptr]), rptr, 1.0);
	}
}

void	load_object(t_object* object, char* path)
{
	int fd;
	int	numrow;
	int	numcol;
	
	fd = open(path, O_RDONLY);
	allocate_mesh_memory(object, &numrow, &numcol, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_fdf_file(object, numrow, numcol, fd);
	close(fd);
}
