/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:54 by geshin            #+#    #+#             */
/*   Updated: 2023/09/05 13:00:37 by geshin           ###   ########.fr       */
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
	
	t_object 	object;
	t_camera	camera;
	t_vshader	vshader;
}	t_program;

void	init_program(t_program* program);
void	destroy_program(t_program* program);

#endif