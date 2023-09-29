/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:04:59 by geshin            #+#    #+#             */
/*   Updated: 2023/09/29 17:15:50 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

char	*cmd_list[11] =
{
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr"
};

void	display_commands(t_vector *commands)
{
	int	i;

	i = 0;
	while (commands->values[i] != END)
	{
		printf("%s", cmd_list[commands->values[i]]);
		i++;
	}
}