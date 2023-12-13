/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 18:55:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATHLIB_H
# define GMATHLIB_H

typedef struct s_vec2
{
	union
	{
		double x;
		double u;
	};
	union
	{
		double y;
		double v;
	};
}	t_vec2;

typedef t_vec2	t_uv;

t_vec2	make_vec2(double x, double y);
t_uv	make_uv(double u, double v);
t_vec2	vec2_plus_vec2(const t_vec2 *v1, const t_vec2 *v2);
t_vec2	vec2_minus_vec2(const t_vec2 *v1, const t_vec2 *v2);
t_vec2	vec2_multiply_vec2(const t_vec2 *v1, const t_vec2 *v2);
t_vec2	vec2_multiply_num(const t_vec2 *v1, double num);
void	clamp_vec2(t_vec2 *out, double min, double max);
double	dot_vec2(const t_vec2 *v1, const t_vec2 *v2);


typedef struct s_vec3
{
	union
	{
		double x;
		double r;
	};
	union
	{
		double y;
		double g;
	};
	union
	{
		double z;
		double b;
	};
}	t_vec3;

typedef t_vec3	t_rgb;

t_vec3	make_vec3(double x, double y, double z);
t_rgb	make_rgb(double r, double g, double b);
t_vec3	vec3_plus_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	vec3_minus_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	vec3_multiply_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	vec3_multiply_num(const t_vec3 *v1, double num);
void	clamp_vec3(t_vec3 *out, double min, double max);
t_vec3	normalize_vec3(const t_vec3 *v);
double	dot_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	cross_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	reflect_vec3(const t_vec3 *v1, const t_vec3 *v2);		//glm::reflect()

typedef struct s_vec4
{
	union
	{
		double x;
		double r;
	};
	union
	{
		double y;
		double g;
	};
	union
	{
		double z;
		double b;	
	};
	union
	{
		double w;
		double a;
	};
}	t_vec4;

typedef t_vec4	t_rgba;

t_vec4	make_vec4(double x, double y, double z, double w);
t_rgba	make_rgba(double r, double g, double b, double a);
t_vec4	vec4_plus_vec4(const t_vec4 *v1, const t_vec4 *v2);
t_vec4	vec4_minus_vec4(const t_vec4 *v1, const t_vec4 *v2);
t_vec4	vec4_multiply_vec4(const t_vec4 *v1, const t_vec4 *v2);
t_vec4	vec4_multiply_num(const t_vec4 *v1, double num);
void	clamp_vec4(t_vec4 *out, double min, double max);
t_vec4	vec3_to_vec4(const t_vec3 *v, double w);
t_vec3	vec4_to_vec3(const t_vec4 *v);


typedef struct s_mat3
{
	double elem[3][3];
}	t_mat3;

t_mat3	identity_mat3(void);
t_mat3	inv_mat3(const t_mat3 *m);
t_mat3	mul_mat3_to_mat3(const t_mat3 *m1, const t_mat3 *m2);
t_vec3	mul_mat3_to_vec3(const t_mat3 *m, const t_vec3 *v);

typedef struct s_mat4
{
	double elem[4][4];
}	t_mat4;

t_mat4	identity_mat4(void);
t_mat4	inv_mat4(const t_mat4 *m);
t_mat4	transpose_mat4(const t_mat4 *m);
t_mat4	mul_mat4_to_mat4(const t_mat4 *m1, const t_mat4 *m2);
t_vec4	mul_mat4_to_vec4(const t_mat4 *m, const t_vec4 *v);
t_mat4	make_view_mat(t_vec3 pos, t_vec3 target, t_vec3 up);			//glm::lookAt();
t_mat4	make_proj_mat(float fov, float aspect, float near, float far);	//glm::perspective();

#endif