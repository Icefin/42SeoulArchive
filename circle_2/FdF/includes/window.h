/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:23:22 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 15:32:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "object.h"
#include "vshader.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define VERT_OFFSET 10

void	init_window(void** mlx, void** window);
void	update_window(void** mlx, void** window, t_vshader* vshader, t_object* obj);

#endif