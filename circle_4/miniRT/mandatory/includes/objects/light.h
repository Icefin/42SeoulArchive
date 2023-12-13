/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 19:07:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "gmathlib.h"

typedef struct s_point_light
{
	t_vec3	position;
	float	brightness;
	t_rgb	rgb;
}	t_point_light;

#endif