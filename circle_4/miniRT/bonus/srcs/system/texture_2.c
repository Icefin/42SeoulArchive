/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:47:34 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 21:56:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "texture.h"

static t_vec3	get_vec3_from_value(t_uint32 value)
{
	t_rgb	dir;
	t_vec3	res;

	dir.r = ((value >> 16) & 0xff) / 255.0;
	dir.g = ((value >> 8) & 0xff) / 255.0;
	dir.b = ((value) & 0xff) / 255.0;

	res.x = dir.g * 2.0 - 1.0;
	res.y = dir.b * 2.0 - 1.0;
	res.z = dir.r * 2.0 - 1.0;
	return (res);
}

static t_vec3	get_texture_value(t_uv uv, const t_image* image)
{
	t_vec3		res;
	char		*dst;
	t_uint32	value;

	dst = image->addr + ((int)uv.v * image->line_length + (int)uv.u * (image->bits_per_pixel / 8));
	value = *(t_uint32 *)dst;
	res = get_vec3_from_value(value);
	return (res);
}

t_vec3	uv_normal_plane(t_vec3 pos, const t_texture *texture)
{
	t_vec3	res;
	t_uv	uv;

	if (pos.x < 0)
		pos.x = texture->width + ((int)pos.x % texture->width);
	else
		pos.x = (int)pos.x % texture->width;
	if (pos.z < 0)
		pos.z = texture->height + ((int)pos.z % texture->height);
	else
		pos.z = (int)pos.z % texture->height;
	uv = make_uv(pos.x, pos.z);
	res = get_texture_value(uv, &(texture->image));
	res = normalize_vec3(res);
	return (res);
}