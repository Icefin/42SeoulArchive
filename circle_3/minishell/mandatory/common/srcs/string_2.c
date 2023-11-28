/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:18:10 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "string.h"

static void	realloc_string(t_string *out)
{
	char	*temp;
	int		prev_len;
	int		i;

	prev_len = out->length;
	temp = (char *)malloc((prev_len + 1) * sizeof(char));
	i = -1;
	while (++i < prev_len)
		temp[i] = out->str[i];
	temp[i] = '\0';
	string_destructor(out);
	string_constructor(out, temp);
	free(temp);
}

void	string_append_char(t_string	*s, char c)
{
	if (s->length >= s->capacity - 1)
		realloc_string(s);
	s->str[s->length] = c;
	s->length++;
}

void	string_append_string(t_string *s, t_string *ap)
{
	int		i;

	i = -1;
	while (++i < ap->length)
		string_append_char(s, ap->str[i]);
}

int	string_compare(t_string *s1, t_string *s2)
{
	int	i;

	if (s1->length != s2->length)
		return (FALSE);
	i = -1;
	while (++i < s1->length)
	{
		if (s1->str[i] != s2->str[i])
			return (FALSE);
	}
	return (TRUE);
}

char	*get_string_c_str(t_string *s)
{
	char	*res;
	int		i;
	int		length;

	if (s == NULL)
		length = 0;
	else
		length = s->length;
	res = (char *)malloc((length + 1) * sizeof(char));
	i = -1;
	while (++i < length)
		res[i] = s->str[i];
	res[i] = '\0';
	return (res);
}
