/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:55:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:48:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	void	*data;
	int		size;
	int		capacity;
}	t_vector;

void	vector_constructor(t_vector *out, int dsize);
void	vector_destructor(t_vector *v, int dsize);

#endif