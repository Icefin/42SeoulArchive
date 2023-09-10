/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:44:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/10 15:03:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void	destroy_program(t_program *program)
{
	int	ptr;

	ptr = -1;
	while (++ptr < program->object.row)
		free(program->object.mesh[ptr]);
	free(program->object.mesh);
	mlx_destroy_window(program->mlx, program->window);
	exit(0);
}

static int	key_event(int key, t_program *program)
{
	if (key == KEY_ESCAPE)
		destroy_program(program);
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
	{
		translate_camera(&(program->camera), key);
		update_view_matrix(&(program->vshader), &(program->camera));
	}
	else if (key == KEY_O || key == KEY_L || key == KEY_K || key == KEY_COLON)
	{
		rotate_camera(&(program->camera), key);
		update_view_matrix(&(program->vshader), &(program->camera));
	}
	else if (key == KEY_Q || key == KEY_E)
	{
		zoom_camera(&(program->camera), key);
		update_projection_matrix(&(program->vshader), &(program->camera));
	}
	else if (key == KEY_P)
	{
		switch_camera_mode(&(program->camera));
		update_projection_matrix(&(program->vshader), &(program->camera));
	}
	update_window(&(program->mlx), &(program->window),
		&(program->vshader), &(program->object));
	return (0);
}

void	init_program(t_program *program)
{
	init_window(&(program->mlx), &(program->window));
	init_camera(&(program->camera));
	init_vertex_shader(&(program->vshader), &(program->camera));
	init_object(&(program->object), program->file_path);
	mlx_hook(program->window, ON_KEYDOWN, 0, key_event, program);
}
