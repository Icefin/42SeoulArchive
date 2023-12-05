/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_transform.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:54:13 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 23:17:59 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TRANSFORM_H
# define C_TRANSFORM_H

# include "gmathlib.h"

typedef struct s_c_transform
{
	t_vec3	position;
	t_vec3	rotation;
	t_vec3	scale;

}	t_c_transform;

void	translate_transform();
void	rotate_transform();
void	scale_transform();

#endif