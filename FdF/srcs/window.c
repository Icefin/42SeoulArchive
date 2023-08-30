/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:25:04 by geshin            #+#    #+#             */
/*   Updated: 2023/08/28 13:03:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
#include "camera.h"
#include "map.h"
#include "vector.h"
#include "matrix.h"
#include "image.h"

#include <stdio.h>

#define DEBUG_MODE

void	bresenham_line_draw(t_image* image, t_vec3 p1, t_vec3 p2, t_vec3 color);

void	init_window(void** mlx, void** window)
{
	*mlx = mlx_init();
	*window = mlx_new_window(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
}

static void	draw_neighbor_line(t_image* image, t_camera* camera, t_vec4 v1, t_vec4 v2, t_vec3 color)
{
	t_vec4	cv1;
	t_vec4	cv2;
	t_vec3	p1;
	t_vec3	p2;

	if (camera->isPerspectiveMode == 0)
	{
		cv1 = multiply_mat4_to_vec4(&(camera->vmatrix), v1);
		cv2 = multiply_mat4_to_vec4(&(camera->vmatrix), v2);
	}
	else if (camera->isPerspectiveMode == 1)
	{
		cv1 = multiply_mat4_to_vec4(&(camera->pvmatrix), v1);
		cv2 = multiply_mat4_to_vec4(&(camera->pvmatrix), v2);
	}
	p1 = make_vec3(cv1.x / cv1.w, cv1.y / cv1.w, cv1.z / cv1.w);
	p2 = make_vec3(cv2.x / cv2.w, cv2.y / cv2.w, cv2.z / cv2.w);
	bresenham_line_draw(image, p1, p2, color);
}

static void	draw_polygon_mesh(t_image* image, t_camera* camera, t_map* map)
{
	int		rptr;
	int		cptr;
	t_vec4	curr;
	t_vec4	next;
	t_vec3 	pColor;

	pColor = make_vec3(1.0f, 1.0f, 1.0f);
	rptr = -1;
	while (++rptr < map->row)
	{
		cptr = -1;
		while (++cptr < map->col)
		{
			curr = make_vec4(cptr * VERT_OFFSET, map->matrix[rptr][cptr] * VERT_OFFSET, rptr * VERT_OFFSET, 1.0);
			if (rptr + 1 < map->row)
			{
				next = make_vec4(cptr * VERT_OFFSET, map->matrix[rptr + 1][cptr] * VERT_OFFSET, (rptr + 1) * VERT_OFFSET, 1.0);
				draw_neighbor_line(image, camera, curr, next, pColor);
			}
			if (cptr + 1 < map->col)
			{
				next = make_vec4((cptr + 1) * VERT_OFFSET, map->matrix[rptr][cptr + 1] * VERT_OFFSET, rptr * VERT_OFFSET, 1.0);
				draw_neighbor_line(image, camera, curr, next, pColor);
			}
		}
	}
}

#ifdef DEBUG_MODE
static void draw_xyz_axis(t_image* image, t_camera* camera)
{
	t_vec4 origin = make_vec4(0.0f, 0.0f, 0.0f, 1.0f);
	t_vec4 xAxis = make_vec4(10000.0f, 0.0f, 0.0f, 1.0f);
	t_vec4 yAxis = make_vec4(0.0f, 10000.0f, 0.0f, 1.0f);
	t_vec4 zAxis = make_vec4(0.0f, 0.0f, 10000.0f, 1.0f);

	t_vec3 xColor = make_vec3(1.0f, 0.0f, 0.0f);
	t_vec3 yColor = make_vec3(0.0f, 1.0f, 0.0f);
	t_vec3 zColor = make_vec3(0.0f, 0.0f, 1.0f);
	
	draw_neighbor_line(image, camera, origin, xAxis, xColor);
	draw_neighbor_line(image, camera, origin, yAxis, yColor);
	draw_neighbor_line(image, camera, origin, zAxis, zColor);
}
#endif

void	update_window(void** mlx, void** window, t_camera* camera, t_map* map)
{
	static int frame = 0;
	t_image	image;
	
	image.img = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
									&image.endian);
	draw_polygon_mesh(&image, camera, map);
#ifdef DEBUG_MODE
	draw_xyz_axis(&image, camera);
#endif
	mlx_put_image_to_window(*mlx, *window, image.img, 0, 0);
	mlx_destroy_image(*mlx, image.img);
	printf("Window Updated! frame : %d\n", frame++);
}