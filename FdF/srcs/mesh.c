/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:55:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/08/30 23:20:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "mesh.h"

static void	allocate_mesh_memory(t_mesh* mesh, int* outrow, int* outcol, int fd)
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
	mesh->numvertices = numcol * numrow;
	mesh->vertices = (t_vec4 *)malloc(mesh->numvertices * sizeof(t_vec4));
}

static void	parse_fdf_file(t_mesh* mesh, int numrow, int numcol, int fd)
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
			mesh->vertices[rptr + cptr] = make_vec4(cptr, ft_getnbr(elements[cptr]), rptr, 1.0);
	}
}

void	init_mesh_object(t_mesh* mesh, char* path)
{
	int fd;
	int	numrow;
	int	numcol;
	
	fd = open(path, O_RDONLY);
	allocate_mesh_memory(mesh, &numrow, &numcol, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_fdf_file(mesh, numrow, numcol, fd);
	close(fd);
}
