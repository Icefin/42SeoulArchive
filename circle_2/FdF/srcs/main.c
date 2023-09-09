/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:12:40 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 16:11:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static int check_valid_argument(int argc, char **argv) 
{
	if ((argc != 2) || argv == NULL)
		return (1);
	return (0);
}

int main(int argc, char **argv) 
{
	t_program	program;

	if (check_valid_argument(argc, argv) != 0)
		return (1);
	program.file_path = argv[1];
	init_program(&program);
	update_window(&(program.mlx), &(program.window), &(program.vshader), &(program.object));
	mlx_loop(program.mlx);
	return (0);
}