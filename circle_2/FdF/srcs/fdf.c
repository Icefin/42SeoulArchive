/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:44:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/19 13:41:04 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void	destroy_program(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->object.row)
		free(program->object.mesh[i]);
	free(program->object.mesh);
	mlx_destroy_window(program->mlx, program->window);
	exit(0);
}

static int	close_window(t_program *program)
{
	destroy_program(program);
	return (0);
}

static int	key_event(int key, t_program *program)
{
	if (key == KEY_ESCAPE)
		close_window(program);
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
	mlx_hook(program->window, ON_DESTROY, 0, close_window, program);
}
