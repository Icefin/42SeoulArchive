/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:21 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 13:00:10 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_word_cnt(const char *s, char c)
{
	int	word_cnt;
	int	left;
	int	right;

	word_cnt = 0;
	left = -1;
	right = 0;
	while (s[right] != '\0')
	{
		if (s[right] == c)
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

static char	*get_word(const char *s, char c, int *idx)
{
	char	*res;
	int		ptr;
	int		len;

	len = 0;
	while (s[*idx + len] != c && s[*idx + len] != '\0')
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ptr = -1;
	while (++ptr < len)
		res[ptr] = s[*idx + ptr];
	res[ptr] = '\0';
	*idx = *idx + len - 1;
	return (res);
}

static void	my_destroy(char	**s, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free(s[idx]);
		idx++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		idx;
	int		res_idx;

	res = (char **)malloc((get_word_cnt(s, c) + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	idx = -1;
	res_idx = 0;
	while (s[++idx] != '\0')
	{
		if (s[idx] != c)
		{
			res[res_idx] = get_word(s, c, &idx);
			if (res[res_idx] == 0)
			{
				my_destroy(res, res_idx);
				return (0);
			}
			res_idx++;
		}
	}
	res[res_idx] = 0;
	return (res);
}
