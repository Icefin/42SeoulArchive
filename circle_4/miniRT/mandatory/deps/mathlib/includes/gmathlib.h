/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 13:28:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATHLIB_H
# define GMATHLIB_H

typedef struct s_vec2
{
	double x;
	double y;
}	t_vec2;

void	make_vec2();
void	dot_vec2();
void	clamp_vec2();

typedef struct s_vec3
{
	double	x;
	double	y;
	double 	z;
}	t_vec3;

void	make_vec3();
void	euler_to_quat();
void	dot_vec3();
void	clamp_vec3();
void	cross_vec3();
void	normalize_vec3();
void	reflect_vec3();

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

void	make_vec4();
void	dot_vec4();
void	vec3_to_vec4();
void	vec4_to_vec3();
void	clamp_vec4();

typedef struct s_mat3
{
	double elem[3][3];
}	t_mat3;

void	identity_mat3();
void	inv_mat3();
void	mul_mat3_to_mat3();
void	mul_mat3_to_vec3();

typedef struct s_mat4
{
	double elem[4][4];
}	t_mat4;

void	identity_mat4();
void	inv_mat4();
void	mul_mat4_to_mat4();
void	mul_mat4_to_vec4(t_mat4 m, t_vec4 v);
void	make_view_mat(t_vec3 pos, t_vec3 target, t_vec3 up);			//glm::lookAt();
void	make_proj_mat(float fovy, float aspect, float near, float far);	//glm::perspective();

typedef struct s_quat
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quat;

void	make_quat();
void	quat_to_euler();

#endif