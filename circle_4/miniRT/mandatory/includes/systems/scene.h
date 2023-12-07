/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:05:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 22:13:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

typedef struct s_scene
{
	t_vector	objects;
	t_vector	lights;
}	t_scene;

void	initialize_scene(t_scene *scene);
void	destroy_scene(t_scene *scene);

#endif