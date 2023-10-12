/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:13:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/12 16:36:01 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG

#include "rstack.h"
#include "vector.h"

#include "parser.h"
#include "sorter.h"
#include "optimizer.h"
#include "displayer.h"

#include <stdio.h>

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

//TODO : RM
void	leaks()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_rstack	stack;
	t_vector	commands;

	//TODO : RM
	atexit(leaks);
	
	if (argc == 1)
	{
		printf("Error : This program requires at least one argument\n");
		return (1);
	}
	init_rstack(&stack);
	parse_arguments(argc, argv, &stack);
	
#ifdef DEBUG
	printf("\n==========Before Sorting==========\n");
	t_node *ptr = stack.top;
	while (ptr != NULL) {
		printf("%d\n", ptr->value);
		ptr = ptr->prev;
	}
	printf("==================================\n\n");
#endif

	if (stack.size <= 1 || is_sorted(&stack) == TRUE)
	{
		destroy_rstack(&stack);
		printf("Stack is already sorted\n");
		return (0);
	}
	malloc_vector(&commands, stack.size * 10);
	sort_stack(&stack, &commands);

#ifdef DEBUG
	printf("\n===========After Sorting==========\n");
	ptr = stack.top;
	while (ptr != NULL) {
		printf("%d\n", ptr->value);
		ptr = ptr->prev;
	}
	printf("==================================\n\n");
#endif

	if (is_sorted(&stack) == FALSE)
	{
		destroy_rstack(&stack);
		destroy_vector(&commands);
		printf("Error : Stack is not sorted! Check sorting step again\n");
		return (1);
	}

#ifdef DEBUG
	printf("\n==========Before Optimize==========\n");
	for (int i = 0; i < commands.size; ++i)
		printf("%d\n", vector_get_index_value(&commands, i));
	printf("====================================\n\n");
#endif

	optimize_commands(&commands);

#ifdef DEBUG
	printf("\n==========After Optimize===========\n");
	for (int i = 0; i < commands.size; ++i)
		printf("%d\n", vector_get_index_value(&commands, i));
	printf("====================================\n\n");
#endif

	printf("\n==========Final Result==========\n");
	display_commands(&commands);
	printf("=================================\n");
	destroy_rstack(&stack);
	destroy_vector(&commands);
	return (0);
}