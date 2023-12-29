/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:21 by geshin            #+#    #+#             */
/*   Updated: 2023/12/20 14:29:45 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static int	is_seperator(char c, char sp)
{
	if (sp == '\0')
	{
		if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
			return (1);
		return (0);
	}
	if (c == sp)
		return (1);
	return (0);
}

static int	get_word_cnt(const char *s, char sp)
{
	int	word_cnt;
	int	left;
	int	right;

	word_cnt = 0;
	left = -1;
	right = 0;
	while (s[right] != '\0')
	{
		if (is_seperator(s[right], sp) == 1)
		{
			if (right - left > 1)
				word_cnt++;
			left = right;
		}
		right++;
	}
	if (right - left > 1)
		word_cnt++;
	return (word_cnt);
}

static char	*get_word(const char *s, char sp, int *idx)
{
	char	*ptr;
	int		len;

	len = 0;
	while (is_seperator(s[*idx + len], sp) == 0 && s[*idx + len] != '\0')
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s[*idx], len + 1);
	*idx = *idx + len - 1;
	return (ptr);
}

static void	my_destroy(char	**s, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		free(s[idx]);
		idx++;
	}
	free(s);
}

char	**ft_split(char const *s, char sp)
{
	char	**res;
	int		idx;
	int		res_idx;

	res = (char **)malloc((get_word_cnt(s, sp) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	idx = -1;
	res_idx = 0;
	while (s[++idx] != '\0')
	{
		if (is_seperator(s[idx], sp) == 0)
		{
			res[res_idx] = get_word(s, sp, &idx);
			if (res[res_idx] == NULL)
			{
				my_destroy(res, res_idx);
				return (NULL);
			}
			res_idx++;
		}
	}
	res[res_idx] = NULL;
	return (res);
}
