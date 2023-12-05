/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:52:44 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 23:06:50 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "gmathlib.h"

typedef struct s_material
{
	t_vec3	ambient;
	t_vec3	specular;
	t_vec3	emissive;
	t_vec3	shininess;
}	t_material;

static const t_material	m_metal = 
{
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f}
};

static const t_material	m_rubber = 
{
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 0.0f}
};

#endif