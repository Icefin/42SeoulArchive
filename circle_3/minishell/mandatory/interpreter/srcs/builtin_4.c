/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:30:50 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 01:54:50 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "map_environment.h"
#include "string.h"
#include "utils.h"

int	execute_env(t_map_env *menv)
{
	char	*key;
	char	*value;
	char	*str;
	int		idx;

	idx = -1;
	while (++idx < menv->key.size)
	{
		key = get_string_c_str(&(menv->key.data[idx]));
		value = get_string_c_str(&(menv->value.data[idx]));
		if (*value != '\0')
		{
			str = ft_strjoin_with_char(key, value, '=');
			printf("%s\n", str);
			free(str);
		}
		free(key);
		free(value);
	}
	return (0);
}
