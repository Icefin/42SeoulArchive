/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:44:26 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 17:11:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	camera_on_update(t_camera *camera)
{
	t_bool	is_moved;

	is_moved = FALSE;
	//check keyboard input
	//check mouse movement

	if (is_moved == TRUE)
	{
		calc_raydirs();
	}
}

void	camera_on_resize(t_camera *camera)
{
	
}