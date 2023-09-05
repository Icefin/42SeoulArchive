/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:23:22 by geshin            #+#    #+#             */
/*   Updated: 2023/09/05 12:59:18 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "object.h"
#include "vshader.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define VERT_OFFSET 30

void	init_window(void** mlx, void** window);
void	update_window(void** mlx, void** window, t_vshader* vshader, t_object* obj);

#endif