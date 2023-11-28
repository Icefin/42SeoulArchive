/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:37:19 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 07:15:45 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

void	stack_int_constructor(t_stack *out, int capacity)
{
	out->data = malloc(sizeof(int) * capacity);
	out->size = 0;
	out->capacity = capacity;
}

void	stack_node_constructor(t_stack *out, int capacity)
{
	out->data = malloc(sizeof(t_node *) * capacity);
	out->size = 0;
	out->capacity = capacity;
}

void	stack_int_destructor(t_stack *st)
{
	free(st->data);
}

void	stack_node_destructor(t_stack *st)
{
	int		i;
	t_node	**ptr;

	i = -1;
	while (++i < st->size)
	{
		ptr = (st->data + (sizeof(t_node *) * i));
		astree_destructor(*ptr);
	}
	free(st->data);
}

t_bool	stack_is_empty(t_stack *st)
{
	if (st->size == 0)
		return (TRUE);
	return (FALSE);
}
