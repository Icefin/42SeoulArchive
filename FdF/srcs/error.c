/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:52:12 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/12 16:34:57 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error_wrong_args(void) {
	printf("Invalid Arguments Error!\n");
	printf("Usage : ./fdf <filename> [ case_size z_size ]");
	return (1);
}

int error_file_open(void) {
	printf("Invalid File Error!");
	return (1);
}

int	error_map_info(void) {
	printf("Invalid Map Error!");
	return (1);
}