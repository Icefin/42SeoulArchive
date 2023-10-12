/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:05 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 15:28:08 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimizer.h"

#include <stdio.h>

void	optimize_commands(t_vector* commands)
{
	t_vector	temp;
	
	malloc_vector(&temp, commands->size);

	//optimize
	
	vector_push_back(commands, END);
	destroy_vector(&temp);
}