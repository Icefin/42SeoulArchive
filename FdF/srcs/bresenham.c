/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:04:02 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 16:07:26 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"

static void ft_mlx_pixel_put(t_image* image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	bresenham_line_draw(t_image* image, t_vec2 p1, t_vec2 p2)
{
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			ft_mlx_pixel_put(image, p1.x * 40 + i, p1.y * 40 + j, 0x00ffffff);
			ft_mlx_pixel_put(image, p2.x * 40 + i, p2.y * 40 + j, 0x00000000);
		}
	}
}