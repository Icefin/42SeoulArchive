/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:05:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:47:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"

typedef struct s_scene
{
	t_object	*camera;

	t_vector	objects;
	t_vector	lights;
}	t_scene;

#endif