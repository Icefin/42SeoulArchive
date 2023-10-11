/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:04:59 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 17:52:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void	display_commands(t_vector *commands)
{
	int	i;

	i = 0;
	while (commands->values[i] != END)
	{
		printf("%s\n", cmd_list[commands->values[i]]);
		i++;
	}
}