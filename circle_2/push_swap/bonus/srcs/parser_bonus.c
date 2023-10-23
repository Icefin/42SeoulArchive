/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:05 by geshin            #+#    #+#             */
/*   Updated: 2023/10/23 14:22:33 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils_bonus.h"
#include "parser_bonus.h"
#include "vector_bonus.h"

static int	process_argument(char *arg, t_rstack *stack)
{
	char		**split;
	int			i;
	long long	num;

	split = ft_split(arg, ' ');
	if (split == NULL)
		return (FALSE);
	i = -1;
	while (split[++i] != NULL)
	{
		num = ft_stoi_plus_imax(split[i]);
		if (num == -1)
		{
			destroy_2d_array(split);
			return (FALSE);
		}
		rstack_push_bottom(stack, num - 2147483648);
	}
	destroy_2d_array(split);
	return (TRUE);
}

static int	is_duplicated_element(t_rstack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->bottom;
	while (first != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (first->value == second->value)
				return (TRUE);
			second = second->next;
		}
		first = first->next;
	}
	return (FALSE);
}

static void	copy_vector_to_stack(t_rstack *stack, t_vector *v)
{
	t_node	*node;
	int		cnt;

	cnt = 0;
	node = stack->bottom;
	while (node != NULL)
	{
		node->value = vector_get_index_value(v, cnt++);
		node = node->next;
	}
}

static void	indexize_elements(t_rstack *stack)
{
	t_vector	temp;
	t_node		*curr;
	t_node		*node;
	int			cnt;

	malloc_vector(&temp, stack->size);
	curr = stack->bottom;
	while (curr != NULL)
	{
		cnt = 0;
		node = stack->bottom;
		while (node != NULL)
		{
			if (node->value < curr->value)
				cnt++;
			node = node->next;
		}
		vector_push_back(&temp, cnt);
		curr = curr->next;
	}
	copy_vector_to_stack(stack, &temp);
	destroy_vector(&temp);
}

void	parse_arguments(int argc, char **argv, t_rstack *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (process_argument(argv[i], stack) == FALSE)
		{
			destroy_rstack(stack);
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	if (is_duplicated_element(stack) == TRUE)
	{
		destroy_rstack(stack);
		write(1, "Error\n", 6);
		exit(1);
	}
	indexize_elements(stack);
}
