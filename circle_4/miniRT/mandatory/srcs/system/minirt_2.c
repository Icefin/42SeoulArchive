/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:19:24 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/01 22:43:06 by jihwjeon         ###   ########.fr       */
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
