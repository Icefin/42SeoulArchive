/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:01:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/10 12:04:01 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "transform.h"
# include "mesh.h"

typedef struct s_object
{
	t_transform	transform;
	t_mesh		mesh;
}	t_object;


#endif