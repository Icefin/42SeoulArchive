/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:05 by geshin            #+#    #+#             */
/*   Updated: 2023/10/02 15:59:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimizer.h"

#include <stdio.h>

void	optimize_commands(t_vector* commands)
{
	for (int i = 0; i < commands->size; ++i)
		printf("%d\n", commands->values[i]);
}