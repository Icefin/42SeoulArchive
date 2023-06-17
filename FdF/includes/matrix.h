/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:29:34 by geshin            #+#    #+#             */
/*   Updated: 2023/06/17 16:22:03 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void	init_identity_mat4(double (*matrix)[4][4]);
void	copy_mat4(double (*dst)[4][4], const double (*src)[4][4]);
void	multiply_mat4_to_mat4(double (*m1)[4][4], double (*m2)[4][4], double (*dst)[4][4]);
t_vec4	multiply_mat4_to_vec4(const double (*m)[4][4], t_vec4 v);
#endif