/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:25:04 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 15:55:30 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
#include "camera.h"
#include "map.h"
#include "vector.h"
#include "image.h"

#include <stdio.h>

void	bresenham_line_draw(t_image* image, t_vec2 p1, t_vec2 p2);

void	init_window(void** mlx, void** window)
{
	*mlx = mlx_init();
	*window = mlx_new_window(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
}

static int	camera_culling(t_camera* camera, t_vec3 v)
{
	int det;

	det = dot_product(camera->gaze, v);
	if (det < 0)
		return (0);
	return (1);
}

static void	draw_neighbor_line(t_image* image, t_camera* camera, t_vec3 v1, t_vec3 v2)
{
	t_vec3	cv1;
	t_vec3	cv2;
	t_vec2	p1;
	t_vec2	p2;

	cv1 = make_vec3(v1.x - camera->position.x, v1.y - camera->position.y, v1.z - camera->position.z);
	if (camera_culling(camera, cv1) == 0)
		return;
	cv2 = make_vec3(v2.x - camera->position.x, v2.y - camera->position.y, v2.z - camera->position.z);
	p1 = make_vec2(cv1.x, cv1.y);
	p2 = make_vec2(cv2.x, cv2.y);
	bresenham_line_draw(image, p1, p2);
}

static void	draw_polygon_mesh(t_image* image, t_camera* camera, t_map* map)
{
	int		rptr;
	int		cptr;
	t_vec3	curr;
	t_vec3	next;

	rptr = -1;
	while (++rptr < map->row)
	{
		cptr = -1;
		while (++cptr < map->col)
		{
			curr = make_vec3(cptr, rptr, map->matrix[rptr][cptr]);
			if (rptr + 1 < map->row)
			{
				next = make_vec3(cptr, rptr + 1, map->matrix[rptr + 1][cptr]);
				draw_neighbor_line(image, camera, curr, next);
			}
			if (cptr + 1 < map->col)
			{
				next = make_vec3(cptr + 1, rptr, map->matrix[rptr][cptr + 1]);
				draw_neighbor_line(image, camera, curr, next);
			}
		}
	}
}

void	update_window(void** mlx, void** window, t_camera* camera, t_map* map)
{
	t_image	image;
	
	image.img = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
									&image.endian);
	draw_polygon_mesh(&image, camera, map);
	mlx_put_image_to_window(*mlx, *window, image.img, 0, 0);
	mlx_destroy_image(*mlx, image.img);
	printf("Window Updated!\n");
}