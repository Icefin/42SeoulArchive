/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:29:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:35:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "gmathlib.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

#endif