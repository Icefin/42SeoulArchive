/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:39:20 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/18 02:47:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

#define FALSE	0
#define TRUE	1

static int	is_sorted(t_rstack *stack)
{
	int		prev;
	t_node	*curr;

	prev = stack->top->value;
	curr = stack->top->prev;	
	while (curr != NULL)
	{
		if (prev > curr->value)
			return (FALSE);
		prev = curr->value;
		curr = curr->prev;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{

}