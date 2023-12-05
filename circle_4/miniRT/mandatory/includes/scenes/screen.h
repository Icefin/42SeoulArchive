/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:43 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/06 00:13:01 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include <mlx.h>

# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600

typedef struct s_screen
{
	void	*mlx;
	void	*window;
}	t_screen;

void	initialize_screen();
void	destroy_screen();

#endif