/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:18:33 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/11 19:39:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "minirt.h"
#include "eventcode.h"

extern void	render(t_minirt *minirt);

#include <stdio.h>
#include <sys/time.h>

t_uint32	gettime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static int key_event(int key, t_minirt *minirt)
{
	t_uint32 time = gettime();
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(minirt->mlx, minirt->window);
		minirt_destructor(minirt);
		exit(0);
	}
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		camera_translate(&(minirt->scene.camera), key);
	else if (key == KEY_1 || key == KEY_2)
		camera_mode_change(&(minirt->scene.camera), key);
	render(minirt);
	printf("[DeltaTime: %dms]\n", gettime() - time);
	return (0);
}

static int mouse_event(int x, int y, t_minirt *minirt)
{
	static int px = WINDOW_WIDTH;
	static int py = WINDOW_HEIGHT;

	t_uint32 time = gettime();
	camera_rotate(&(minirt->scene.camera), x - px, y - py);
	px = x;
	py = y;
	render(minirt);
	printf("[DeltaTime: %dms]\n", gettime() - time);
	return (0);
}

static void event_hook(t_minirt *minirt)
{
	mlx_hook(minirt->window, ON_KEYDOWN, 0, key_event, minirt);
	mlx_hook(minirt->window, ON_MOUSEMOVE, 0, mouse_event, minirt);
}

void	minirt_constructor(t_minirt *minirt, char *file)
{
	scene_constructor(&(minirt->scene), file);
	minirt->mlx = mlx_init();
	minirt->window = mlx_new_window(minirt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");

	minirt->scene.checker.image.img = mlx_xpm_file_to_image(minirt->mlx,\
													"./assets/checker.xpm",\
													&minirt->scene.checker.width,\
													&minirt->scene.checker.height);
	minirt->scene.checker.image.addr = mlx_get_data_addr(minirt->scene.checker.image.img,\
													&(minirt->scene.checker.image.bits_per_pixel),\
													&(minirt->scene.checker.image.line_length),\
													&(minirt->scene.checker.image.endian));

	minirt->scene.normal.image.img = mlx_xpm_file_to_image(minirt->mlx,\
															"./assets/Asphalt_1.xpm",
															&minirt->scene.normal.width,
															&minirt->scene.normal.height);
	minirt->scene.normal.image.addr = mlx_get_data_addr(minirt->scene.normal.image.img,\
													&(minirt->scene.normal.image.bits_per_pixel),\
													&(minirt->scene.normal.image.line_length),\
													&(minirt->scene.normal.image.endian));
	event_hook(minirt);
}

void	minirt_destructor(t_minirt *minirt)
{
	scene_destructor(&(minirt->scene));	
}