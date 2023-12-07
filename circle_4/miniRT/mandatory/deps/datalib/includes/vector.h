/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:55:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/06 23:23:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	void	*data;
	int		size;
	int		capacity;
	int		dsize;
}	t_vector;

void	vector_constructor(t_vector *out, int capacity, int dsize);
void	vector_destructor(t_vector *v);

void	vector_insert_index(t_vector *out, void data, int idx);

#endif