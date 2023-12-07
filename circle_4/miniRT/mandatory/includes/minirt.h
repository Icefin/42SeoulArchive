/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:59:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 16:04:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"
# include "window.h"
# include "renderer.h"
# include "inputmanager.h"

typedef struct s_minirt
{
	t_window		window;
	t_scene			scene;
	
	t_renderer		renderer;
	t_inputmanager	inputmanager;
}	t_minirt;

void	initialize_minirt(t_minirt *minirt);
void	destroy_minirt(t_minirt *minirt);

void	begin_minirt(t_minirt *minirt);

#endif
