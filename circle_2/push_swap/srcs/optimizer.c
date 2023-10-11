/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:05 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 18:27:17 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimizer.h"

void	optimize_commands(t_vector* commands)
{
	t_vector	*temp;
	
	malloc_vector(temp, commands->size);
	//optimize
	
	vector_push_back(commands, END);
}