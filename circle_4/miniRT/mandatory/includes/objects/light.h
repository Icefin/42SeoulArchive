/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:34:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "transform.h"

typedef struct s_dir_light
{
	t_transform	transform;
}	t_dir_light;

t_dir_light	make_dir_light();

typedef struct s_spot_light
{
	t_transform	transform;
}	t_spot_light;

t_spot_light make_spot_light();

typedef struct s_point_light
{
	t_transform	transform;
}	t_point_light;

t_point_light make_point_light();

#endif