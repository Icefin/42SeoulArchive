/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:09:34 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/19 15:43:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void	*fbuffer;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

#endif