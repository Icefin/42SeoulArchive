/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:44:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/05 13:17:11 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#include <stdio.h>

#include "fdf.h"

void	destroy_program(t_program* program)
{
	int	ptr;

	ptr = -1;
	while (++ptr < program->object.row)
		free(program->object.mesh[ptr]);
	free(program->object.mesh);
	mlx_destroy_window(program->mlx, program->window);
	printf("Program Destroy");
	exit(0);
}

static int	key_event(int keycode, t_program* program)
{
	if (keycode == KEY_ESCAPE)
		destroy_program(program);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
	{
		translate_camera(&(program->camera), keycode);
		update_view_matrix(&(program->vshader), &(program->camera));
	}
	else if (keycode == KEY_O || keycode == KEY_L || keycode == KEY_K || keycode == KEY_COLON)
	{
		rotate_camera(&(program->camera), keycode);
		update_view_matrix(&(program->vshader), &(program->camera));
	}
	else if (keycode == KEY_Q || keycode == KEY_E)
	{
		zoom_camera(&(program->camera), keycode);
		update_projection_matrix(&(program->vshader), &(program->camera));
	}
	else if (keycode == KEY_P)
	{
		switch_camera_mode(&(program->camera));
		update_projection_matrix(&(program->vshader), &(program->camera));
	}
	update_window(&(program->mlx), &(program->window), &(program->vshader), &(program->object));
	return (0);
}

void	init_program(t_program* program)
{
	printf("Init Window!\n");
	init_window(&(program->mlx), &(program->window));

	printf("Init Camera!\n");
	init_camera(&(program->camera));

	printf("Init Vertex Shader!\n");
	init_vertex_shader(&(program->vshader), &(program->camera));

	printf("Init Single Object!\n");
	init_object(&(program->object), program->file_path);

	printf("Init Hooks!\n");
	mlx_hook(program->window, ON_KEYDOWN, 0, key_event, program);
}
