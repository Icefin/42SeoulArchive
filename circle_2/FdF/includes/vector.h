/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:38 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 14:18:05 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

t_vec3	make_vec3(double x, double y, double z);
t_vec4	make_vec4(double x, double y, double z, double w);
void	normalize_vec3(t_vec3 *v);
double	dot_product(const t_vec3 v1, const t_vec3 v2);
t_vec3	cross_product(const t_vec3 v1, const t_vec3 v2);

#endif