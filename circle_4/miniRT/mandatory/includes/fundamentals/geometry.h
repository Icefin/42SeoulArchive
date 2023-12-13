/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:00:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 19:11:49 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "ray.h"
# include "object.h"

void	raycast_sphere(const t_ray *ray, const t_object *sphere, t_rayinfo *out);
void	raycast_plane(const t_ray *ray, const t_object *plane, t_rayinfo *out);
void	raycast_cylinder(const t_ray *ray, const t_object *cylinder, t_rayinfo *out);

#endif