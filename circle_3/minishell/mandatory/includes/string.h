/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:24:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 17:28:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

typedef struct s_string
{
	char	*str;
	int		length;
	int		capacity;
}	t_string;

t_string	*string_constructor(int length);
void		string_destructor(t_string	*s);

void		string_append(t_string	*s, char c);
int			string_compare(t_string *s1, t_string *s2);

#endif