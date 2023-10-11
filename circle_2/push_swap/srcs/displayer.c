/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:04:59 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 14:51:18 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static char	*cmd_list[11] =
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
		printf("%s\n", cmd_list[commands->values[i]]);
		i++;
	}
}