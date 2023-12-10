/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:34:41 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:25:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	initialize_renderer(t_renderer *renderer, const t_scene *scene, const t_camera *camera)
{
	renderer->m_scene = scene;
	renderer->m_camera = camera;
	renderer->framecnt = 1;
}

void	destroy_renderer(t_renderer *renderer)
{
	
}