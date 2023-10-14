/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:04:59 by geshin            #+#    #+#             */
/*   Updated: 2023/10/15 02:09:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

#include <stdio.h>

void	display_commands(t_vector *commands)
{
	static char	*cmd_list[11] = { "sa", "sb", "ss", "pa", "pb",
								 "ra", "rb", "rr", "rra", "rrb", "rrr" };
	int	i;

	i = 0;
	while (commands->values[i] != END)
	{
		printf("%s\n", cmd_list[commands->values[i]]);
		i++;
	}
	//printf("Commands Number : %d\n", commands->size);
}