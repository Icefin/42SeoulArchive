/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:59:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 16:01:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "window.h"
# include "scene.h"
# include "renderer.h"

typedef struct s_minirt
{
	t_window		window;

	t_scene			scene;
	t_renderer		renderer;
}	t_minirt;

void	initialize_minirt(t_minirt *minirt);
void	destroy_minirt(t_minirt *minirt);

void	begin_minirt(t_minirt *minirt);

#endif
