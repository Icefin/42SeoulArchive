/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:33:56 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 04:06:57 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "token.h"

void	token_constructor(t_token *out, t_token_type type, t_string *data)
{
	char	*tmp;

	out->type = type;
	tmp = get_string_c_str(data);
	string_constructor(&(out->data), tmp);
	free(tmp);
}

void	token_destructor(t_token *token)
{
	string_destructor(&(token->data));
}
