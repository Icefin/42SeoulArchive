/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:23:22 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 15:03:57 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "object.h"
# include "vshader.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

void	init_window(void **mlx, void **window);
void	update_window(void **mlx, void **window, t_vshader *vs, t_object *obj);

#endif