/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:59:11 by geshin            #+#    #+#             */
/*   Updated: 2023/08/30 23:31:20 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

#include <stdio.h>

#ifdef DEBUG_MODE
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
#endif

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
	if (keycode == KEY_ESCAPE)
		destroy_program(program);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
		translate_camera(&(program->camera), keycode);
	else if (keycode == KEY_O || keycode == KEY_K || keycode == KEY_L || keycode == KEY_COLON)
		rotate_camera(&(program->camera), keycode);
	else if (keycode == KEY_P)
		switch_camera_mode(&(program->camera));
	update_window(&(program->mlx), &(program->window), &(program->camera), &(program->map));
	return (0);
}

void	init_program(t_program* program)
{
	printf("Init Window!\n");
	init_window(&(program->mlx), &(program->window));
	
	//printf("Init Map!\n");
	//init_map(&(program->map), program->file_path);

	printf("Load Object!\n");
	load_object(&(program->object), program->file_path);
		
#ifdef DEBUG_MODE
	test_map_print(program);
#endif
	
	printf("Init Camera!\n");
	init_camera(&(program->camera));

	printf("Init Hooks!\n");
	mlx_hook(program->window, ON_KEYDOWN, 0, key_event, program);
}

