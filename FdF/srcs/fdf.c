/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:59:11 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 16:12:39 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

#include <stdio.h>

static void test_map_print(t_program* p) {
	for (int r = 0; r < p->map.row; r++) {
		for (int c = 0; c < p->map.col; c++) {
			printf("%d ", p->map.matrix[r][c]);
		}
		printf("\n");
	}
	printf("Row Len : %d\n", p->map.row);
	printf("Col Len : %d\n", p->map.col);
}

void	destroy_program(t_program* program)
{
	int	ptr;

	ptr = -1;
	while (++ptr < program->map.row)
		free(program->map.matrix[ptr]);
	free(program->map.matrix);
	mlx_destroy_window(program->mlx, program->window);
	printf("Program Destroy");
	exit(0);
}

static int	key_event(int keycode, t_program* program)
{
	t_vec3	v;
	if (keycode == KEY_ESCAPE)
		destroy_program(program);
	else if (keycode == KEY_W) {
		v = make_vec3(0, 1, 0);
		translate_camera(&(program->camera), v);
	}
	else if (keycode == KEY_A) {
		v = make_vec3(-1, 0, 0);
		translate_camera(&(program->camera), v);
	}	
	else if (keycode == KEY_S) {
		v = make_vec3(0, -1, 0);
		translate_camera(&(program->camera), v);
	}
	else if (keycode == KEY_D) {
		v = make_vec3(1, 0, 0);
		translate_camera(&(program->camera), v);
	}
	update_window(&(program->mlx), &(program->window), &(program->camera), &(program->map));
	return (0);
}

void	init_program(t_program* program)
{
	printf("Init Window!\n");
	init_window(&(program->mlx), &(program->window));
	
	printf("Init Map!\n");
	init_map(&(program->map), program->file_path);
	test_map_print(program);

	printf("Init Camera!\n");
	init_camera(&(program->camera));

	printf("Init Hooks!\n");
	mlx_hook(program->window, ON_KEYDOWN, 0, key_event, program);
}

