/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:43:38 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/21 14:53:19 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

size_t	gnl_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*gnl_strdup(const char *s)
{
	char	*str;
	int		size;

	size = 0;
	while (s[size])
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	size = 0;
	while (s[size])
	{
		str[size] = s[size];
		size++;
	}
	str[size] = 0;
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != (char)c)
		idx++;
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		idx_to;
	int		idx_from;

	str = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	idx_to = 0;
	idx_from = 0;
	while (s1[idx_from])
		str[idx_to++] = s1[idx_from++];
	idx_from = 0;
	while (s2[idx_from])
		str[idx_to++] = s2[idx_from++];
	str[idx_to] = '\0';
	free(s1);
	return (str);
}

char	*gnl_substr(char const *s, size_t start, size_t len, size_t s_size)
{
	char	*str;
	size_t	idx;

	if (s_size <= start)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (s_size - start + 1 <= len)
		str = (char *)malloc(sizeof(char) * (s_size - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		str[idx] = s[start + idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
