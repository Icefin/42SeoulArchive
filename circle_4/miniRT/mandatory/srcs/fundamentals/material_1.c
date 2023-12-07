/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:15:04 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:15:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	make_material(t_vec3 albedo, float roughness, float metalic)
{
	t_material	res;

	res.albedo = albedo;
	res.roughness = roughness;
	res.metalic = metalic;
	return (res);
}