/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:05 by geshin            #+#    #+#             */
/*   Updated: 2023/09/27 18:42:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

static int process_argument(char* arg, t_rstack *stack)
{
	char	**split;

	split = ft_split(arg);
}

void	parse_arguments(int argc, char **argv, t_rstack *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (process_argument(argv[i], stack) == FALSE)
		{
			//memory free
			//exit
		}
	}
}