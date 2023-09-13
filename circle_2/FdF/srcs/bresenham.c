/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:04:02 by geshin            #+#    #+#             */
/*   Updated: 2023/09/13 15:03:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"
#include "window.h"

static	void	ft_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static	void	plot_line_low(t_image *img, t_vec3 p1, t_vec3 p2)
{
	int		dx;
	int		dy;
	int		yi;
	int		determinant;
	t_vec3	pixel;

	dx = p2.x - p1.x;
	yi = 1;
	if (p2.y - p1.y < 0)
		yi = -1;
	dy = fabs(p2.y - p1.y);
	determinant = (2 * dy) - dx;
	pixel = make_vec3(p1.x, p1.y, 0.0);
	while (pixel.x <= p2.x)
	{
		ft_mlx_pixel_put(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (determinant > 0)
		{
			pixel.y += yi;
			determinant += 2 * (dy - dx);
		}
		else
			determinant += 2 * dy;
		pixel.x++;
	}
}

static	void	plot_line_high(t_image *img, t_vec3 p1, t_vec3 p2)
{
	int		dx;
	int		dy;
	int		xi;
	int		determinant;
	t_vec3	pixel;

	dy = p2.y - p1.y;
	xi = 1;
	if (p2.x - p1.x < 0)
		xi = -1;
	dx = fabs(p2.x - p1.x);
	determinant = (2 * dx) - dy;
	pixel = make_vec3(p1.x, p1.y, 0.0);
	while (pixel.y <= p2.y)
	{
		ft_mlx_pixel_put(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (determinant > 0)
		{
			pixel.x += xi;
			determinant += 2 * (dx - dy);
		}
		else
			determinant += 2 * dx;
		pixel.y++;
	}
}

void	bresenham_line_draw(t_image *img, t_vec3 p1, t_vec3 p2)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			plot_line_low(img, p2, p1);
		else
			plot_line_low(img, p1, p2);
	}
	else
	{
		if (p1.y > p2.y)
			plot_line_high(img, p2, p1);
		else
			plot_line_high(img, p1, p2);
	}
}
