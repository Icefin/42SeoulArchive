/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:06:25 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 15:59:51 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_minirt(t_minirt *minirt)
{
	initialize_scene(&(minirt->scene));
	initialize_window(&(minirt->window));
	initialize_renderer(&(minirt->renderer), &(minirt->scene));
}

void	destroy_minirt(t_minirt *minirt)
{
	destroy_scene(&(minirt->scene));
	destroy_window(&(minirt->window));
	destroy_renderer(&(minirt->renderer));
}