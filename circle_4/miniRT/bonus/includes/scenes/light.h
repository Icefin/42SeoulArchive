/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:03:17 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 16:07:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rtmath.h"

typedef struct s_light
{
	t_vec3	position;

	t_rgb	albedo;
	float	brightness;

	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;
}	t_light;

t_light	make_light(t_vec3 pos, t_rgb albedo, float brightness);

#endif