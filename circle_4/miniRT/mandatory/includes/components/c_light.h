/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_light.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:59:23 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:26:13 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_LIGHT_H
# define C_LIGHT_H

typedef enum e_light_type
{
	POINT,
	SPOT,
	DIRECTIONAL,
	AREA
}	t_light_type;

typedef struct s_c_light
{
	t_light_type	type;
	
}	t_c_light;

#endif