/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:39:28 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 10:52:38 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

static void	stack_node_realloc(t_stack *st)
{
	t_node	**tmp;
	int		prev_size;
	int		i;
	t_node	**ptr;

	prev_size = st->size;
	tmp = (t_node **)malloc(sizeof(t_node *) * prev_size);
	i = -1;
	while (++i < prev_size)
	{
		ptr = (st->data + (sizeof(t_node *) * i));
		tmp[i] = astree_copy(*ptr);
	}
	stack_node_destructor(st);
	stack_node_constructor(st, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
		stack_node_push(st, tmp[i]);
	i = -1;
	while (++i < prev_size)
		astree_destructor(tmp[i]);
	free(tmp);
}

void	stack_node_push(t_stack *st, t_node *node)
{
	t_node	**ptr;

	if (st->size == st->capacity)
		stack_node_realloc(st);
	ptr = (st->data + (sizeof(t_node *) * st->size));
	*ptr = astree_copy(node);
	st->size++;
}

void	stack_node_pop(t_stack *st)
{
	t_node	**ptr;

	if (stack_is_empty(st) == TRUE)
		return ;
	ptr = (st->data + (sizeof(t_node *) * (st->size - 1)));
	astree_destructor(*ptr);
	st->size--;
}

int	stack_node_top_type(t_stack *st)
{
	t_node	**ptr;

	if (stack_is_empty(st) == TRUE)
		return (DEFAULT);
	ptr = (st->data + (sizeof(t_node *) * (st->size - 1)));
	return ((*ptr)->token.type);
}

void	stack_node_top(t_stack *st, t_node **out)
{
	t_node	**ptr;

	if (stack_is_empty(st) == TRUE)
	{
		*out = NULL;
		return ;
	}
	ptr = (st->data + (sizeof(t_node *) * (st->size - 1)));
	*out = astree_copy(*ptr);
}
