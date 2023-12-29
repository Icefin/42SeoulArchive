/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:15:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/21 16:46:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"

typedef struct s_minirt
{
	t_scene		scene;

	void		*mlx;
	void		*window;
}	t_minirt;

void	minirt_constructor(t_minirt *minirt, char *file);
void	minirt_destructor(t_minirt *minirt);

void	minirt_run(t_minirt *minirt);

#endif