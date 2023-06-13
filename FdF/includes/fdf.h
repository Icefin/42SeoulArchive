/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 12:26:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "error.h"
#include "camera.h"
#include "controller.h"
#include "map.h"
#include "libft.h"
#include "window.h"

typedef struct s_program {
	char	*file_path;
	int		fd;
	void	*mlx;
	void	*window;
	
	t_map 		map;
	t_camera	camera;
}	t_program;

void	init_program(t_program* program);
void	destroy_program(t_program* program);

#endif