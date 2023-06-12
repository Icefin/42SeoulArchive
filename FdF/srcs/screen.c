/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:55:11 by geshin            #+#    #+#             */
/*   Updated: 2023/06/12 18:22:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color) {
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	update_screen(t_program* program)
{
	t_image	image;
	
	
	image.img = mlx_new_image(program->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
									&image.endian);
	//get screen coordinates from world coordinates
	
	//draw lines with VERT_OFFSET
	for (int x = 400; x < 1000; x++) {
		for (int y = 300; y < 600; y++) {
			my_mlx_pixel_put(&image, x, y, 0x00ffffff);
		}
	}
	//put image to window
	mlx_put_image_to_window(program->mlx, program->window, image.img, 0, 0);
	mlx_destroy_image(program->mlx, image.img);
}