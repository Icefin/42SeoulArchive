/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/11 20:10:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "error.h"
#include "camera.h"
#include "controller.h"
#include "vertice.h"
#include "map.h"

typedef struct s_program {
	char	*file_path;
	int		fd;
	t_map 	map;
}	t_program;

void	init_map(t_program* program);

#endif