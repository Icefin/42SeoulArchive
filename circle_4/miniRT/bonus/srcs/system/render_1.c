/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:31:16 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 17:44:49 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include <mlx.h>
#include "ray.h"
#include "image.h"
#include "minirt.h"
#include "thread.h"

extern t_rgb	trace_ray(t_ray ray, t_scene *scene, int depth);

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

void*	routine(void *attr)
{
	t_child 	*child = (t_child *)attr;
	t_minirt	*minirt = child->minirt;
	t_camera	*camera = &(child->minirt->scene.camera);
	t_ray		ray;

	ray.origin = camera->position;

	for (t_uint32 y = child->miny; y < child->maxy; y += camera->k)
	{
		for (t_uint32 x = 0; x < WINDOW_WIDTH; x += camera->k)
		{
			ray.direction = *(t_vec3 *)vector_get_idx(&(camera->raydirs), x + y * WINDOW_WIDTH);
			ray.maxdist = camera->far;
			t_rgb pixel_color = trace_ray(ray, &(minirt->scene), 0);
			ft_mlx_pixel_put(child->image, x, y, get_color_from_rgb(pixel_color));
		}
	}
}

void	render(t_minirt *minirt)
{
	t_image		image;
	t_ray		ray;
	t_camera	*camera;

	camera = &(minirt->scene.camera);
	image.img = mlx_new_image(minirt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	ray.origin = camera->position;

#define MT 1
#if MT
	t_child		*child = (t_child *)malloc(sizeof(t_child) * THREAD_CNT);

	for (int i = 0; i < THREAD_CNT; ++i)
	{
		child[i].image = &image;
		child[i].minirt = minirt;
		child[i].miny = ((float)i / THREAD_CNT) * WINDOW_HEIGHT;
		child[i].maxy = ((float)(i + 1) / THREAD_CNT) * WINDOW_HEIGHT;
		pthread_create(&child[i].thread, 0, (void *)routine, (void *)&child[i]);
	}

	for (int i = 0; i < THREAD_CNT; ++i)
		pthread_join(child[i].thread, NULL);
	mlx_put_image_to_window(minirt->mlx, minirt->window, image.img, 0, 0);
	free(child);
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
	mlx_put_image_to_window(minirt->mlx, minirt->window, image.img, 0, 0);
#endif
	mlx_destroy_image(minirt->mlx, image.img);
}