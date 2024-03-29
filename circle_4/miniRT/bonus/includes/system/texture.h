/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:43 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 14:09:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "rtmath.h"
# include "image.h"

typedef enum e_texture_type
{
	TEX_BUMP = 0,
	TEX_NORMAL,
	TEX_CHECKER
}	t_texture_type;

typedef struct s_texture
{
	t_texture_type	type;

	int				width;
	int				height;
	t_image			image;
}	t_texture;

t_rgb	uv_texture_plane(t_vec3 pos, const t_texture *texture);
t_vec3	uv_normal_plane(t_vec3 pos, const t_texture *texture);

#endif