/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:29:34 by geshin            #+#    #+#             */
/*   Updated: 2023/08/31 18:10:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_mat4
{
	union
	{
		double columns[4][4];
		double elements[16];
	};
} t_mat4;

void	init_zero_mat4(double (*matrix)[4][4]);
void	init_identity_mat4(double (*matrix)[4][4]);
void	copy_mat4(double (*dst)[4][4], const double (*src)[4][4]);
void	multiply_mat4_to_mat4(double (*m1)[4][4], double (*m2)[4][4], double (*dst)[4][4]);
t_vec4	multiply_mat4_to_vec4(const double (*m)[4][4], t_vec4 v);
#endif