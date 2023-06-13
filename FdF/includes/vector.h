/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:38 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 15:30:54 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2
{
	double x;
	double y;
}	t_vec2;

typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

t_vec2	make_vec2(int x, int y);
t_vec3	make_vec3(int x, int y, int z);
double	dot_product(const t_vec3 v1, const t_vec3 v2);
t_vec3	cross_product(const t_vec3 v1, const t_vec3 v2);
//t_vec2	project_to_plane(t_vec3 normal, t_vec3 origin, t_vec3 point);

#endif