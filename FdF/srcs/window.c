/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:25:04 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 02:14:23 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <stdio.h>

#include "window.h"
#include "vshader.h"
#include "object.h"
#include "vector.h"
#include "matrix.h"
#include "image.h"

void	bresenham_line_draw(t_image* image, t_vec3 p1, t_vec3 p2, t_vec3 color);

void	init_window(void** mlx, void** window)
{
	*mlx = mlx_init();
	*window = mlx_new_window(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
}

static void	draw_neighbor_line(t_image* image, t_vshader* vshader, t_vec4 v1, t_vec4 v2, t_vec3 color)
{
	t_vec3	p1;
	t_vec3	p2;

	vertex_transform(vshader, v1, &p1);
	vertex_transform(vshader, v2, &p2);
	if (p1.x < 0 || p1.x > 1920 || p1.y < 0 || p1.y > 1080 || p1.z < 0 || p1.z > 1)
		return;
	bresenham_line_draw(image, p1, p2, color);
}

static void	draw_polygon_mesh(t_image* image, t_vshader* vshader, t_object* obj)
{
	int		rptr;
	int		cptr;
	t_vec4	curr;
	t_vec4	next;
	t_vec3 	pcolor;

	pcolor = make_vec3(1.0, 1.0, 1.0);
	rptr = -1;
	while (++rptr < obj->row)
	{
		cptr = -1;
		while (++cptr < obj->col)
		{
			curr = make_vec4(cptr * VERT_OFFSET, obj->mesh[rptr][cptr] * 5, rptr * VERT_OFFSET, 1.0);
			if (rptr + 1 < obj->row)
			{
				next = make_vec4(cptr * VERT_OFFSET, obj->mesh[rptr + 1][cptr] * 5, (rptr + 1) * VERT_OFFSET, 1.0);
				draw_neighbor_line(image, vshader, curr, next, pcolor);
			}
			if (cptr + 1 < obj->col)
			{
				next = make_vec4((cptr + 1) * VERT_OFFSET, obj->mesh[rptr][cptr + 1] * 5, rptr * VERT_OFFSET, 1.0);
				draw_neighbor_line(image, vshader, curr, next, pcolor);
			}
		}
	}
}

static void draw_xyz_axis(t_image* image, t_vshader* vshader)
{
	t_vec4 origin = make_vec4(0.0, 0.0, 0.0, 1.0);
	t_vec4 xaxis = make_vec4(100.0, 0.0, 0.0, 1.0);
	t_vec4 yaxis = make_vec4(0.0, 100.0, 0.0, 1.0);
	t_vec4 zaxis = make_vec4(0.0, 0.0, 100.0, 1.0);

	t_vec3 xcolor = make_vec3(1.0, 0.0, 0.0);
	t_vec3 ycolor = make_vec3(0.0, 1.0, 0.0);
	t_vec3 zcolor = make_vec3(0.0, 0.0, 1.0);
	
	draw_neighbor_line(image, vshader, origin, xaxis, xcolor);
	draw_neighbor_line(image, vshader, origin, yaxis, ycolor);
	draw_neighbor_line(image, vshader, origin, zaxis, zcolor);
}

void	update_window(void** mlx, void** window, t_vshader* vshader, t_object* obj)
{
	static int frame = 0;
	t_image	image;
	
	image.img = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
									&image.endian);
	draw_polygon_mesh(&image, vshader, obj);
	draw_xyz_axis(&image, vshader);
	
	mlx_put_image_to_window(*mlx, *window, image.img, 0, 0);
	mlx_destroy_image(*mlx, image.img);
	printf("Window Updated! frame : %d\n", frame++);
}