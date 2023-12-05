/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:57:31 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:44:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VSHADER_H
# define VSHADER_H

# include "gmathlib.h"

typedef struct s_vshader
{
	t_mat4	worldmat;
	t_mat4	viewmat;
	t_mat4	projmat;
	t_mat4	vportmat;
}	t_vshader;

void	initialize_vshader();
void	process_vshader();

void	update_world_matrix();
void	update_view_matrix();
void	update_projection_matrix();
void	update_viewport_matrix();

#endif