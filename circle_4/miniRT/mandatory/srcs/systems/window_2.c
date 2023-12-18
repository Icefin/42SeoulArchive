/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:56:25 by geshin            #+#    #+#             */
/*   Updated: 2023/12/18 15:57:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "window.h"

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

# define KEY_ESCAPE		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

static int	close_window()
{
	
}

static int	key_event(int key)
{
	if (key == KEY_W)
	{

	}
	else if (key == KEY_A)
	{

	}
	else if (key == KEY_S)
	{

	}
	else if (key == KEY_D)
	{

	}
}

static int	mouse_event(int mouse)
{
	
}

void	inputhook(t_window *window)
{
	printf("\n=====Start Initialize InputManager=====\n");
	mlx_hook(window, ON_DESTROY, 0, close_window, NULL);
	mlx_hook(window, ON_KEYDOWN, 0, key_event, NULL);
	mlx_hook(window, ON_MOUSEMOVE, 0, mouse_event, NULL);
	printf("=====Finish Initialize InputManager=====\n");
}