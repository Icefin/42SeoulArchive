/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:24:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 18:02:33 by singeonho        ###   ########.fr       */
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

void	string_constructor(t_string *out, char *c_str);
void	string_destructor(t_string *s);

void	string_append_char(t_string	*s, char c);
void	string_append_string(t_string *s, t_string *ap);
int		string_compare(t_string *s1, t_string *s2);
char	*get_string_c_str(t_string *s);

#endif