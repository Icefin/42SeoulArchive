/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:43:35 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 15:54:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "gmathlib.h"

typedef struct s_transform
{
	t_vec3	position;
	t_vec3	rotation;
	t_vec3	scale;

}	t_transform;

void	translate_transform(t_vec3 *position);
void	rotate_transform(t_vec3 *rotation);
void	scale_transform(t_vec3 *sccale);
void	get_forward_direction(const t_vec3 *rotation);

#endif