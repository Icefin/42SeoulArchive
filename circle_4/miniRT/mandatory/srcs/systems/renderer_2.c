/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:35:15 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 15:23:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "renderer.h"

static void	mlx_pixel_put(t_image *image, t_uint32 x, t_uint32 y, t_uint32 color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(t_uint32 *)dst = color;
}

void	render_screen(t_renderer *renderer, t_window *window)
{
	t_image	image;
	t_ray	ray;

	image.fbuffer = mlx_new_image(window->mlx, renderer->m_camera->width, renderer->m_camera->height);
	image.addr = mlx_get_data_addr(image.fbuffer, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	ray.origin = renderer->m_camera->transform.position;

#define MT 0
#if MT
	//Multithreaded code comes here...
#else
	for (t_uint32 y = 0; y < renderer->m_camera->height; ++y)
	{
		for (t_uint32 x = 0; x < renderer->m_camera->width; ++x)
		{
			ray.direction = *(t_vec3 *)vector_get_idx(&(renderer->m_camera->raydirs), x + y * renderer->m_camera->width);
			t_uint32 pixel_color = per_pixel(ray);
			mlx_pixel_put(&image, x, y, pixel_color);
		}
	}
#endif
	mlx_put_image_to_window(window->mlx, window, image.fbuffer, 0, 0);
	mlx_destroy_image(window->mlx, image.fbuffer);
}

t_uint32	per_pixel(t_ray ray)
{
	//t_uint32	pixel_color;
	t_rayinfo	rayinfo;

	rayinfo = trace_ray(ray);
	if (rayinfo.ray_time == -1.0f)
		return (0x000000ff);
	//Lighting...
	//reflection
	//refraction
	//absorption
	return (0xff0000ff);
}

t_rayinfo	trace_ray(t_ray	ray)
{
	t_int32	id = -1;
	float	ray_time = __FLT_MAX__;

	if (id == -1)
		return miss(ray);
	return closest_hit(ray, ray_time, id);
}

t_rayinfo	closest_hit(t_ray ray, float ray_time, t_int32 object_id)
{
	t_rayinfo	rayinfo;

	rayinfo.raytime = ray_time;
	rayinfo.object_id = object_id;
	//rayinfo.hit_position = position of hit in world;
	//rayinfo.hit_normal = normal of hit position in world;
	return (rayinfo);
}

t_rayinfo	miss(t_ray ray)
{
	t_rayinfo	rayinfo;

	rayinfo.raytime = -1.0f;
	return (rayinfo);
}