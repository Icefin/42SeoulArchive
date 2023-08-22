/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:04:02 by geshin            #+#    #+#             */
/*   Updated: 2023/08/22 13:59:32 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"
#include "window.h"

static	int	ft_create_trgb(int t, int r, int g, int b) {
	return (t << 24 | r << 16 | g << 8 | b);
}

static void ft_mlx_pixel_put(t_image* image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return;
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static	void	plotLineLow(t_image* image, t_vec3 p1, t_vec3 p2, t_vec3 color)
{
	int	dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = p1.y;
	for (int x = p1.x; x <= p2.x; x++) {
		ft_mlx_pixel_put(image, x, y, ft_create_trgb(0, color.x * 255, color.y * 255, color.z * 255));
		if (D > 0) {
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else {
			D = D + 2 * dy;
		}
	}
}

static	void	plotLineHigh(t_image* image, t_vec3 p1, t_vec3 p2, t_vec3 color)
{
	int	dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = p1.x;
	for (int y = p1.y; y <= p2.y; y++) {
		ft_mlx_pixel_put(image, x, y, ft_create_trgb(0, color.x * 255, color.y * 255, color.z * 255));
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}

void	bresenham_line_draw(t_image* image, t_vec3 p1, t_vec3 p2, t_vec3 color)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x)) {
		if (p1.x > p2.x)
			plotLineLow(image, p2, p1, color);
		else
			plotLineLow(image, p1, p2, color);
	}
	else {
		if (p1.y > p2.y)
			plotLineHigh(image, p2, p1, color);
		else
			plotLineHigh(image, p1, p2, color);
	}
}