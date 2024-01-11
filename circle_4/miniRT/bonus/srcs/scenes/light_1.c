/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:15:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/31 01:07:41 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	make_light(t_vec3 pos, t_rgb albedo, float brightness)
{
	t_light	light;

	light.position = pos;
	light.albedo = albedo;
	light.brightness = brightness;
	return (light);
}