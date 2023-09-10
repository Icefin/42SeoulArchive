/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:25:04 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 15:01:10 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
#include "vshader.h"
#include "object.h"
#include "vector.h"
#include "matrix.h"
#include "image.h"

void	bresenham_line_draw(t_image *image, t_vec3 p1, t_vec3 p2);

void	init_window(void **mlx, void **window)
{
	*mlx = mlx_init();
	*window = mlx_new_window(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
}

static void	draw_line(t_image *image, t_vshader *vshader, t_vec4 v1, t_vec4 v2)
{
	t_vec3	p1;
	t_vec3	p2;

	vertex_transform(vshader, v1, &p1);
	vertex_transform(vshader, v2, &p2);
	if (p1.x < 0 || p1.x > 1024
		|| p1.y < 0 || p1.y > 768
		|| p1.z < 0 || p1.z > 1)
		return ;
	bresenham_line_draw(image, p1, p2);
}

static void	draw_mesh(t_image *image, t_vshader *vshader, t_object *obj)
{
	int		r;
	int		c;
	t_vec4	cvert;
	t_vec4	nvert;

	r = -1;
	while (++r < obj->row)
	{
		c = -1;
		while (++c < obj->col)
		{
			cvert = make_vec4(c, obj->mesh[r][c], r, 1.0);
			if (r + 1 < obj->row)
			{
				nvert = make_vec4(c, obj->mesh[r + 1][c], (r + 1), 1.0);
				draw_line(image, vshader, cvert, nvert);
			}
			if (c + 1 < obj->col)
			{
				nvert = make_vec4((c + 1), obj->mesh[r][c + 1], r, 1.0);
				draw_line(image, vshader, cvert, nvert);
			}
		}
	}
}

void	update_window(void **mlx, void **window, t_vshader *vs, t_object *obj)
{
	t_image	image;

	image.img = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	draw_mesh(&image, vs, obj);
	mlx_put_image_to_window(*mlx, *window, image.img, 0, 0);
	mlx_destroy_image(*mlx, image.img);
}
