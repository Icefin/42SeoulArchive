/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 17:42:37 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATHLIB_H
# define GMATHLIB_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double 	z;
}	t_vec3;

void	initialize_vec3();
void	euler_to_quat();

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

void	initialize_vec4();

typedef struct s_mat3
{
	double elem[3][3];
}	t_mat3;

void	identity_mat3();
void	multiply_mat3_to_mat3();
void	multiply_mat3_to_vec3();

typedef struct s_mat4
{
	double elem[4][4];
}	t_mat4;

void	identity_mat4();
void	multiply_mat4_to_mat4();
void	multiply_mat4_to_vec4();

typedef struct s_quat
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quat;

void	quat_to_euler();

#endif