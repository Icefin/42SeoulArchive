/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:05 by geshin            #+#    #+#             */
/*   Updated: 2023/09/29 16:57:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"
#include "vector.h"

static int	process_argument(char* arg, t_rstack *stack)
{
	char		**split;
	int			i;
	long long	num;

	split = ft_split(arg, ' ');
	i = -1;
	while (split[++i] != NULL) {
		num = ft_stoi_plus_imax(split[i]);
		if (num == -1) {
			destroy_2d_array(split);
			return (FALSE);
		}
		rstack_push_bottom(stack, num - 2147483648);
	}
	destroy_2d_array(split);
	return (TRUE);
}

static int	is_duplicated_element(t_rstack* stack)
{
	//Two Pointer   -> n^2
	//or Sorting... -> n + nlogn + n
	return (FALSE);
}

void	parse_arguments(int argc, char **argv, t_rstack *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (process_argument(argv[i], stack) == FALSE)
		{
			destroy_stack(stack);
			printf("Error : Invalid Input\n");
			exit(1);
		}
	}
	if (is_duplicated_element(stack) == TRUE)
	{
		destroy_rstack(stack);
		printf("Error : Duplicated Element\n");
		exit(1);
	}
}