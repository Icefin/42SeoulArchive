/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:03:35 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/05 15:34:08 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "utils.h"
#include "rtmath.h"
#include "scene.h"

extern void	ft_free_2d_char(char **words);
extern int	set_ambient(t_scene *scene, char **words);
extern int	set_camera(t_scene *scene, char **words);
extern int	set_light(t_scene *scene, char **words);
extern int	set_sphere(t_scene *scene, char **words, int id);
extern int	set_plane(t_scene *scene, char **words, int id);
extern int	set_cylinder(t_scene *scene, char **words, int id);
extern int	set_cone(t_scene *scene, char **words, int id);

int	str_to_vec3(t_vec3 *pos, char *str)
{
	char	**words;

	words = ft_split(str, ',');
	if (words == NULL || words[0] == NULL
		|| words[1] == NULL || words[2] == NULL
		|| words[3] != NULL)
	{
		ft_free_2d_char(words);
		return (1);
	}
	*pos = make_vec3(ft_atod(words[0]), ft_atod(words[1]), ft_atod(words[2]));
	ft_free_2d_char(words);
	return (0);
}

int	str_to_rgb(t_rgb *rgb, char *str)
{
	char	**words;

	words = ft_split(str, ',');
	if (words == NULL || words[0] == NULL
		|| words[1] == NULL || words[2] == NULL
		|| words[3] != NULL)
	{
		ft_free_2d_char(words);
		return (1);
	}
	*rgb = make_rgb(ft_atod(words[0]), ft_atod(words[1]), ft_atod(words[2]));
	ft_free_2d_char(words);
	return (0);
}

int	set_informations(t_scene *scene, char *line)
{
	static int	id;
	char		**words;
	int			status;

	status = 1;
	words = ft_split(line, '\0');
	if (words == NULL || *words == NULL)
		return (1);
	if (ft_strcmp(words[0], "A") == 0)
		status = set_ambient(scene, words);
	else if (ft_strcmp(words[0], "C") == 0)
		status = set_camera(scene, words);
	else if (ft_strcmp(words[0], "L") == 0)
		status = set_light(scene, words);
	else if (ft_strcmp(words[0], "sp") == 0)
		status = set_sphere(scene, words, id++);
	else if (ft_strcmp(words[0], "pl") == 0)
		status = set_plane(scene, words, id++);
	else if (ft_strcmp(words[0], "cy") == 0)
		status = set_cylinder(scene, words, id++);
	else if (ft_strcmp(words[0], "cn") == 0)
		status = set_cone(scene, words, id++);
	ft_free_2d_char(words);
	return (status);
}

void	parser_error(t_scene *scene, char *msg)
{
	ft_putstr_fd(msg, 2);
	scene_destructor(scene);
	exit(1);
}

void	init_scene_from_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		parser_error(scene, "Error\n");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, "\n") != 0)
		{
			if (set_informations(scene, line) != 0)
			{
				parser_error(scene, "Error\n");
				return ;
			}
		}
		free(line);
	}
}
