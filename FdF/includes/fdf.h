/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/12 16:49:08 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "error.h"
#include "camera.h"
#include "controller.h"
#include "map.h"
#include "libft.h"

typedef struct s_program {
	char	*file_path;
	int		fd;
	void	*mlx;
	void	*window;
	
	t_map 		map;
	t_camera	camera;
}	t_program;

#include "screen.h"

void	init_program(t_program* program);
void	init_map(t_program* program);
void	init_controller(t_program* program);
void	init_camera(t_camera* camera);
void	destroy_program(t_program* program);

#endif