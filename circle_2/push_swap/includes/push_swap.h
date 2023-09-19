/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:08:14 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/19 17:38:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "rstack.h"
#include "parser.h"

typedef struct s_program
{
	t_rstack stack_a;
	t_rstack stack_b;

	t_parser parser;
	
}	t_program;

int	program_parse(t_program *program, int argc, char **argv);
int	program_sort(t_program *program);
int	program_display(t_program *program);

#endif