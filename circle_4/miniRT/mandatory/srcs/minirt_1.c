/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:06:25 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/06 00:08:28 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_minirt(t_minirt *minirt)
{
	initialize_scene(&(minirt->scene));
	initialize_screen(&(minirt->screen));
}

void	destroy_minirt(t_minirt *minirt)
{
	destroy_scene(&(minirt->scene));
	destroy_screen(&(minirt->screen));
}