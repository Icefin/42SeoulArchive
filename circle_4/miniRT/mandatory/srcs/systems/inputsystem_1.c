/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputsystem_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:39:10 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 16:02:10 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inputmanager.h"

static int	close_window()
{
	
}

static int	key_event(int key)
{
	
}

static int	mouse_event(int mouse)
{
	
}

static int	pick_event(int mouse)
{
	
}

void	initialize_inputmanager(void *window)
{
	printf("\n=====Start Initialize InputManager=====\n");
	mlx_hook(window, ON_DESTROY, 0, close_window, NULL);
	mlx_hook(window, ON_KEYDOWN, 0, key_event, NULL);
	mlx_hook(window, ON_MOUSEMOVE, 0, mouse_event, NULL);
	mlx_hook(window, ON_MOUSEDOWN, 0, pick_event, NULL);
	printf("=====Finish Initialize InputManager=====\n");
}