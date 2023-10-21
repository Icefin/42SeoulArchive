/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:39:20 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/21 17:41:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "commands.h"
#include "parser.h"
#include "rstack.h"

#define FALSE	0
#define TRUE	1

int	process_command(t_rstack *a, t_rstack *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		cmd_swap_top_a(a, NULL);
	else if (ft_strncmp(cmd, "sb\n", 4) == 0)
		cmd_swap_top_b(b, NULL);
	else if (ft_strncmp(cmd, "ss\n", 4) == 0)
		cmd_swap_top_all(a, b, NULL);
	else if (ft_strncmp(cmd, "pa\n", 4) == 0)
		cmd_push_to_a(b, a, NULL);
	else if (ft_strncmp(cmd, "pb\n", 4) == 0)
		cmd_push_to_b(a, b, NULL);
	else if (ft_strncmp(cmd, "ra\n", 4) == 0)
		cmd_rotate_a(a, NULL);
	else if (ft_strncmp(cmd, "rb\n", 4) == 0)
		cmd_rotate_b(b, NULL);
	else if (ft_strncmp(cmd, "rr\n", 4) == 0)
		cmd_rotate_all(a, b, NULL);
	else if (ft_strncmp(cmd, "rra\n", 5) == 0)
		cmd_reverse_rotate_a(a, NULL);
	else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		cmd_reverse_rotate_b(b, NULL);
	else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		cmd_reverse_rotate_all(a, b, NULL);
	else
		return (FALSE);
	return (TRUE);
}

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
	char		*cmd;
	t_rstack	a_stack;
	t_rstack	b_stack;

	if (argc == 1)
		return (0);
	init_rstack(&a_stack);
	init_rstack(&b_stack);
	parse_arguments(argc, argv, &a_stack);
	while (TRUE) {
		cmd = read();
		if (cmd == NULL)
			break;
		if (process_command(&a_stack, &b_stack, cmd) == FALSE)
		{
			write(1, "Error\n", 6);
			destroy_rstack(&a_stack);
			destroy_rstack(&b_stack);
			free(cmd);
			return (1);
		}
	}
	if (is_sorted(&a_stack) == TRUE && b_stack.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	destroy_rstack(&a_stack);
	destroy_rstack(&b_stack);
	return (0);
}