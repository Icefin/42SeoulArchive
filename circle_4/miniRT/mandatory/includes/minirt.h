/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:59:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/06 00:08:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"
# include "screen.h"

typedef struct s_minirt
{
	t_scene		scene;
	t_screen	screen;
}	t_minirt;

void	initialize_minirt(t_minirt *minirt);
void	destroy_minirt(t_minirt *minirt);

void	begin_minirt(t_minirt *minirt);

#endif