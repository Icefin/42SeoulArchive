/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:23:22 by geshin            #+#    #+#             */
/*   Updated: 2023/06/17 14:49:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "camera.h"
#include "map.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define VERT_OFFSET 30

void	init_window(void** mlx, void** window);
void	update_window(void** mlx, void** window, t_camera* camera, t_map* map);

#endif