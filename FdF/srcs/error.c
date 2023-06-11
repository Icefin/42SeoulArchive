/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:52:12 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/11 20:24:28 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error_wrong_args(void) {
	printf("Invalid Arguments Error!");
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