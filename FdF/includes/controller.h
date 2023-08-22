/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:05:29 by geshin            #+#    #+#             */
/*   Updated: 2023/08/22 15:09:20 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

enum EVENT {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum KEYCODE {
	KEY_ESCAPE = 53, 

	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,

	KEY_O = 31,
	KEY_K = 40,
	KEY_L = 37,
	KEY_COLON = 41,

	KEY_Q = 12,
	KEY_E = 14
};

#endif