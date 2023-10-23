/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:39:20 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 14:26:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "commands_bonus.h"
#include "utils_bonus.h"
#include "parser_bonus.h"
#include "rstack_bonus.h"

#define FALSE	0
#define TRUE	1

int	process_command(t_rstack *a, t_rstack *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		cmd_swap_top_a_bonus(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		cmd_swap_top_b_bonus(b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		cmd_swap_top_all_bonus(a, b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		cmd_push_to_a_bonus(b, a);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		cmd_push_to_b_bonus(a, b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		cmd_rotate_a_bonus(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		cmd_rotate_b_bonus(b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		cmd_rotate_all_bonus(a, b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		cmd_reverse_rotate_a_bonus(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		cmd_reverse_rotate_b_bonus(b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		cmd_reverse_rotate_all_bonus(a, b);
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

static void	display_result(t_rstack *a, t_rstack *b)
{
	if (b->size == 0 && is_sorted(a) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char		cmd[5];
	t_rstack	a_stack;
	t_rstack	b_stack;

	if (argc == 1)
		return (0);
	init_rstack(&a_stack);
	init_rstack(&b_stack);
	parse_arguments(argc, argv, &a_stack);
	while (TRUE)
	{
		if (read(0, cmd, 5) == 0)
			break ;
		if (process_command(&a_stack, &b_stack, cmd) == FALSE)
		{
			write(1, "Error\n", 6);
			destroy_rstack(&a_stack);
			destroy_rstack(&b_stack);
			return (1);
		}
	}
	display_result(&a_stack, &b_stack);
	destroy_rstack(&a_stack);
	destroy_rstack(&b_stack);
	return (0);
}
