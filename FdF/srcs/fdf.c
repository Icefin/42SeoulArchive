/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:59:11 by geshin            #+#    #+#             */
/*   Updated: 2023/06/12 17:24:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit(0);
}

int	key_event(int keycode, t_program* program)
{
	if (keycode == KEY_ESCAPE)
		destroy_program(program);
	update_screen(program);
	return (0);
}

void	init_program(t_program* program)
{
	printf("Init Program!\n");
	program->mlx = mlx_init();
	program->window = mlx_new_window(program->mlx, \
						WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	printf("Init Map!\n");
	init_map(program);
	test_map_print(program);

	printf("Init Camera!\n");
	init_camera(&(program->camera));

	printf("Init Hooks!\n");
	mlx_hook(program->window, ON_KEYDOWN, 0, key_event, program);
}

