/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:29:34 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 14:47:40 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef double	t_mat4[4][4];

void	init_zero_mat4(t_mat4 *m);
void	init_identity_mat4(t_mat4 *m);
void	copy_mat4(t_mat4 *dst, t_mat4 *src);
void	multiply_mat4_to_mat4(t_mat4 *m1, t_mat4 *m2, t_mat4 *dst);
t_vec4	multiply_mat4_to_vec4(t_mat4 *m, t_vec4 v);

#endif