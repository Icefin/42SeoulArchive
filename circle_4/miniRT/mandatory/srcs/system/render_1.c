/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:31:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 15:51:50 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <mlx.h>
#include "ray.h"
#include "image.h"
#include "minirt.h"

t_rgb	per_pixel(t_ray ray, t_scene *scene);

static t_uint32	get_color_from_rgb(t_rgb rgb)
{
	return (((int)rgb.r & 0xff) << 16) | (((int)rgb.g & 0xff) << 8) | (((int)rgb.b & 0xff));
}

static void	ft_mlx_pixel_put(t_image *image, t_uint32 x, t_uint32 y, t_uint32 color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(t_uint32 *)dst = color;
}

void	render(t_minirt *minirt)
{
	t_image		image;
	t_ray		ray;
	t_camera	*camera;

	camera = &(minirt->scene.camera);
	image.fbuffer = mlx_new_image(minirt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.fbuffer, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	ray.origin = camera->position;

#define MT 0
#if MT
	//Multithreaded code comes here...
#else
	for (t_uint32 y = 0; y < WINDOW_HEIGHT; y += camera->k)
	{
		for (t_uint32 x = 0; x < WINDOW_WIDTH; x += camera->k)
		{
			ray.direction = *(t_vec3 *)vector_get_idx(&(camera->raydirs), x + y * WINDOW_WIDTH);
			ray.maxdist = camera->far;
			t_rgb pixel_color = per_pixel(ray, &(minirt->scene));
			ft_mlx_pixel_put(&image, x, y, get_color_from_rgb(pixel_color));
		}
	}
#endif
	mlx_put_image_to_window(minirt->mlx, minirt->window, image.fbuffer, 0, 0);
	mlx_destroy_image(minirt->mlx, image.fbuffer);
}