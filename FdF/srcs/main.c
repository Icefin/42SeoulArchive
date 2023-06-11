/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:12:40 by geshin            #+#    #+#             */
/*   Updated: 2023/06/11 20:14:28 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_program program;

	if (check_valid_argument(argc, argv) != 0)
		return (1);
	program.file_path = argv[1];
	init_map(&program);
	for (int r = 0; r < program.map.row; r++) {
		for (int c = 0; c < program.map.col; c++) {
			printf("%d, ", program.map.matrix[r][c]);
		}
		printf("\n");
	}
	return (0);
}