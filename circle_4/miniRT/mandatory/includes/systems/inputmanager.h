/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputmanager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:53:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 18:47:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTMANAGER_H
# define INPUTMANAGER_H

# include <mlx.h>
# include "gmathlib.h"
# include "commontype.h"

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

typedef struct s_inputmanager
{
	t_vec2	mouse_prev;
	t_vec2	mouse_curr;
}	t_inputmanager;

void	initialize_inputmanager();

#endif