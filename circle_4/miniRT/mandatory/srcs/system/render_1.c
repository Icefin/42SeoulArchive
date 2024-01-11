/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:31:16 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 14:31:50 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <mlx.h>
#include "ray.h"
#include "image.h"
#include "minirt.h"

extern t_rgb	per_pixel(t_ray ray, t_scene *scene);

static t_uint32	get_color_from_rgb(t_rgb rgb)
{
	return ((((int)rgb.r & 0xff) << 16) | \
			(((int)rgb.g & 0xff) << 8) | \
			(((int)rgb.b & 0xff)));
}

static void	ft_mlx_pixel_put(t_image *img, t_uint32 x, t_uint32 y, t_uint32 c)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + \
						x * (img->bits_per_pixel / 8));
	*(t_uint32 *)dst = c;
}

void	render_loop(t_minirt *minirt, t_camera *cam, t_ray *ray, t_image *img)
{
	t_uint32	y;
	t_uint32	x;
	t_rgb		pixel_color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ray->direction = *(t_vec3 *)vector_get_idx(&(cam->raydirs), \
													x + y * WINDOW_WIDTH);
			ray->maxdist = cam->far;
			pixel_color = per_pixel(*ray, &(minirt->scene));
			ft_mlx_pixel_put(img, x, y, get_color_from_rgb(pixel_color));
			x += cam->k;
		}
		y += cam->k;
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
	render_loop(minirt, camera, &ray, &image);
	mlx_put_image_to_window(minirt->mlx, minirt->window, image.img, 0, 0);
	mlx_destroy_image(minirt->mlx, image.img);
}
