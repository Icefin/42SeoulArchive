/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:12:40 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 13:21:38 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static int check_valid_argument(int argc, char **argv) {
	if ((argc != 2 && argc != 4) || argv == NULL)
		return (error_wrong_args());
	return (0);
}

int main(int argc, char **argv) {
	t_program	program;

	if (check_valid_argument(argc, argv) != 0)
		return (1);
	program.file_path = argv[1];
	init_program(&program);
	update_window(&(program.mlx), &(program.window), &(program.camera), &(program.map));
	mlx_loop(program.mlx);
	return (0);
}