/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:52:44 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 13:50:57 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "gmathlib.h"

typedef struct s_material
{
	t_vec3	albedo;
	float	roughness;
	float	metalic;
}	t_material;

t_material	make_material(t_vec3 albedo, float roughness, float metalic);

#endif