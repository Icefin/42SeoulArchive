/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:44:32 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/10 11:45:13 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "vertex.h"

typedef struct s_triangle
{
	t_vertex	a;
	t_vertex	b;
	t_vertex	c;
}	t_triangle;




#endif