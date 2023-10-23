/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:26 by geshin            #+#    #+#             */
/*   Updated: 2023/10/23 13:40:51 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

# include <stdlib.h>
# define FALSE		0
# define TRUE		1

typedef struct s_vector
{
	int		*values;
	int		size;
	int		capacity;
}	t_vector;

void	malloc_vector(t_vector *v, int n);
void	destroy_vector(t_vector *v);

void	vector_push_back(t_vector *v, int val);
void	vector_pop_back(t_vector *v);

int		vector_get_index_value(t_vector *v, int idx);
int		vector_get_back(t_vector *v);
int		vector_is_empty(t_vector *v);

#endif