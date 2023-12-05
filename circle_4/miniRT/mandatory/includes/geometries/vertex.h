/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:35:56 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "gmathlib.h"

typedef struct s_vertex
{
	t_vec3	position;
	t_vec3	normal;
	t_vec3	color;
}	t_vertex;

#endif