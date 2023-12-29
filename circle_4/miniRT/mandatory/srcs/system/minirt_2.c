/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:19:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/22 14:09:21 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"

void	render(t_minirt *minirt);

void	minirt_run(t_minirt *minirt)
{
	render(minirt);
	mlx_loop(minirt->mlx);
}