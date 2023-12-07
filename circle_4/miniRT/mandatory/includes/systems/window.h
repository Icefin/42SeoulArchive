/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:43 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 15:55:55 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

void	initialize_window(t_window *window);
void	destroy_window(t_window *window);

#endif