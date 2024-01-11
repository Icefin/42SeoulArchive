/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:15:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/01 22:43:27 by jihwjeon         ###   ########.fr       */
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
