/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:54 by geshin            #+#    #+#             */
/*   Updated: 2023/09/04 13:43:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "camera.h"
#include "controller.h"
#include "vshader.h"
#include "window.h"

typedef struct s_program
{
	char	*file_path;
	int		fd;
	void	*mlx;
	void	*window;
	
	t_map 		map;
	t_camera	camera;
	t_vshader	vshader;
}	t_program;

void	init_program(t_program* program);
void	destroy_program(t_program* program);

#endif