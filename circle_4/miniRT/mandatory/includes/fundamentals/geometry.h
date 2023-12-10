/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:00:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/10 12:01:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "triangle.h"
# include "ray.h"

t_rayinfo	raycast_triangle(const t_ray *ray, const t_triangle *triangle);


#endif