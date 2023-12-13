/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:00:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 16:30:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "ray.h"
# include "object.h"

t_rayinfo	raycast_sphere(const t_ray *ray, const t_object *sphere);
t_rayinto	raycast_plane(const t_ray *ray, const t_object *plane);
t_rayinfo	raycast_cylinder(const t_ray *ray, const t_object *cylinder);
t_rayinfo	raycast_cone(const t_ray *ray, const t_object *cone);


#endif