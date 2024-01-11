/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:42 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/01 22:42:53 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "minirt.h"
#include "eventcode.h"

extern void	render(t_minirt *minirt);

static int	key_event(int key, t_minirt *minirt)
{
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
	return (0);
}

static int	mouse_event(int x, int y, t_minirt *minirt)
{
	static int	px = WINDOW_WIDTH;
	static int	py = WINDOW_HEIGHT;

	camera_rotate(&(minirt->scene.camera), x - px, y - py);
	px = x;
	py = y;
	render(minirt);
	return (0);
}

static void	event_hook(t_minirt *minirt)
{
	mlx_hook(minirt->window, ON_KEYDOWN, 0, key_event, minirt);
	mlx_hook(minirt->window, ON_MOUSEMOVE, 0, mouse_event, minirt);
}

void	minirt_constructor(t_minirt *minirt, char *file)
{
	scene_constructor(&(minirt->scene), file);
	minirt->mlx = mlx_init();
	minirt->window = mlx_new_window(minirt->mlx, \
						WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	event_hook(minirt);
}

void	minirt_destructor(t_minirt *minirt)
{
	scene_destructor(&(minirt->scene));
}
