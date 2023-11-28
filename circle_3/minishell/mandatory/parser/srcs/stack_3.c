/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:43:20 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 01:31:54 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

static void	stack_int_realloc(t_stack *st)
{
	int	*tmp;
	int	prev_size;
	int	i;
	int	*ptr;

	prev_size = st->size;
	tmp = (int *)malloc(sizeof(int) * prev_size);
	i = -1;
	while (++i < prev_size)
	{
		ptr = (st->data + sizeof(int) * i);
		tmp[i] = *ptr;
	}
	stack_int_destructor(st);
	stack_int_constructor(st, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
	{
		ptr = (st->data + sizeof(int) * i);
		*ptr = tmp[i];
	}
	free(tmp);
}

void	stack_int_push(t_stack *st, int i)
{
	int	*ptr;

	if (st->size == st->capacity)
		stack_int_realloc(st);
	ptr = (st->data + sizeof(int) * st->size);
	*ptr = i;
	st->size++;
}

void	stack_int_pop(t_stack *st)
{
	if (stack_is_empty(st) == TRUE)
		return ;
	st->size--;
}

int	stack_int_top(t_stack *st)
{
	int	*ptr;

	if (stack_is_empty(st) == TRUE)
		return (-2);
	ptr = (st->data + sizeof(int) * (st->size - 1));
	return (*ptr);
}
