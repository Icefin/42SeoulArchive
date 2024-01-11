/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:50:03 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/08 12:14:08 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "commontype.h"
#include "minirt.h"
#include "utils.h"

static t_bool	is_valid_file_extension(char *name)
{
	char	*rev;

	rev = ft_revstr(name);
	if (ft_strncmp(rev, "tr.", 3) != 0)
	{
		free(rev);
		return (FALSE);
	}
	free(rev);
	return (TRUE);
}

static t_bool	is_valid_input(int argc, char** argv)
{
	if (argc != 2)
		return (FALSE);
	if (is_valid_file_extension(argv[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}

void leaks()
{
	system("leaks minirt");
}

int main(int argc, char** argv)
{
	atexit(leaks);
	t_minirt	minirt;

	if(is_valid_input(argc, argv) == FALSE)
	{
		printf("Invalid Input:: Input should be (  ./minirt *.rt )\n");
		return (0);
	}
	minirt_constructor(&(minirt), argv[1]);
	minirt_run(&(minirt));
}