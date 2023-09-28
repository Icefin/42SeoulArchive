/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:05 by geshin            #+#    #+#             */
/*   Updated: 2023/09/28 14:54:23 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

static int	process_argument(char* arg, t_rstack *stack)
{
	char		**split;
	int			i;
	long long	num;

	split = ft_split(arg, ' ');
	i = -1;
	while (split[++i] != NULL) {
		num = ft_atoi_plus_int_max(split[i]);
		if (num == -1) {
			//memory free
			//exit
		}
		rstack_push_bottom(stack, num - 2147483648);
	}
}

static int	is_duplicate_element(t_rstack* stack)
{
	
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
	if (is_duplicate_element(stack) == TRUE)
	{
		//memory free
		//exit
	}
}