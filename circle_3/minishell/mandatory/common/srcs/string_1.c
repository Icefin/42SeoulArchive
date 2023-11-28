/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:04:40 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "string.h"

static int	ft_c_str_len(char *c_str)
{
	int	len;

	if (c_str == NULL)
		return (0);
	len = -1;
	while (c_str[++len] != '\0')
		;
	return (len);
}

void	string_constructor(t_string *out, char *c_str)
{
	int	strlen;
	int	i;

	strlen = ft_c_str_len(c_str);
	out->str = (char *)malloc((2 * strlen) * sizeof(char));
	i = -1;
	while (++i < strlen)
		out->str[i] = c_str[i];
	out->length = strlen;
	out->capacity = 2 * strlen;
}

void	string_destructor(t_string *s)
{
	if (s->str != NULL)
		free(s->str);
}
