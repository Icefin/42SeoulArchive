/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:25 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 16:14:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_object
{
	int** 	mesh;
	int 	row;
	int 	col;
}	t_object;

void	init_object(t_object* obj, char* path);

#endif