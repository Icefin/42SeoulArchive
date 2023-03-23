/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:21 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 19:40:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_word_cnt(const char *s, char c)
{
	int	left;
	int	right;
	int	word_cnt;

	left = -1;
	right = 0;
	word_cnt = 0;
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

char	*get_word(const char *s, char c, int *idx)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s[*idx + len] != c && s[*idx + len] != '\0')
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s[*idx], len + 1);
	*idx = *idx + len - 1;
	return (ptr);
}

void	my_destroy(char	**s, size_t size)
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

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		idx;
	int		res_idx;
	size_t	word_cnt;

	word_cnt = get_word_cnt(s, c);
	res = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	idx = -1;
	res_idx = -1;
	while (s[++idx] != '\0')
	{
		if (s[idx] != c)
		{
			res[++res_idx] = get_word(s, c, &idx);
			if (res[res_idx] == NULL)
			{
				my_destroy(res, word_cnt + 1);
				return (NULL);
			}
		}
	}
	res[word_cnt] = NULL;
	return (res);
}
