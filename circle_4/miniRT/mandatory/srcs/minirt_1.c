/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:06:25 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:31:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_minirt(t_minirt *minirt)
{
	initialize_scene(&(minirt->scene));
	initialize_window(&(minirt->window));
	initialize_inputmanager(&(minirt->inputmanager));
	initialize_renderer(&(minirt->renderer), &(minirt->scene), &(minirt->camera));
}

void	destroy_minirt(t_minirt *minirt)
{
	destroy_scene(&(minirt->scene));
	destroy_window(&(minirt->window));
	destroy_inputmanager(&(minirt->inputmanager));
	destroy_renderer(&(minirt->renderer));
}