/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:27:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/21 17:40:07 by singeonho        ###   ########.fr       */
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
void	vector_n_constructor(t_vector *out, int size, int dsize);
void	vector_destructor(t_vector *v);
void	vector_resize(t_vector *out, int size);

void	*vector_get_idx(const t_vector *v, int idx);
void	vector_set_idx(const t_vector *v, int idx, const void *data);
void	vector_push_back(t_vector *v, const void *data);
void	vector_pop_back(t_vector *v);

#endif