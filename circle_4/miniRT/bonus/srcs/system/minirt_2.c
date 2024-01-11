/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:19:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/31 01:10:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"

extern void	render(t_minirt *minirt);

void	minirt_run(t_minirt *minirt)
{
	render(minirt);
	mlx_loop(minirt->mlx);
}