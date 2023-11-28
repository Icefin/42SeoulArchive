/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_string.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:14:13 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/06 18:02:12 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_STRING_H
# define VECTOR_STRING_H

# include "string.h"

typedef struct s_vector_string
{
	t_string	*data;
	int			size;
	int			capacity;
}	t_vector_string;

void	vector_string_constructor(t_vector_string *out, int size);
void	vector_string_destructor(t_vector_string *v);

void	vector_string_push_back(t_vector_string *v, t_string *s);
void	vector_string_pop_back(t_vector_string *v);
void	vector_string_swap(t_vector_string *v, int i, int j);

int		vector_string_is_empty(t_vector_string *v);

#endif