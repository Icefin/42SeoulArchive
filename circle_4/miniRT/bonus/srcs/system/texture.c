/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:54:44 by geshin            #+#    #+#             */
/*   Updated: 2024/01/12 13:36:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "texture.h"

static t_vec3	get_vec3_from_value(t_uint32 value)
{
	t_vec3	res;

	res.x = (value >> 16) & 0xff;
	res.y = (value >> 8) & 0xff;
	res.z = (value) & 0xff;
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

t_rgb	uv_checker_plane(t_vec3 pos, const t_texture *texture)
{
	t_rgb	res;
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