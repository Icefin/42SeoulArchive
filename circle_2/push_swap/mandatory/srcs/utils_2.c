/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:28:57 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 16:43:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	idx;

	if (dstsize == 0)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] != '\0' && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}

static char	*get_word(char *s, char c, int *idx)
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

char	**ft_split(char *s, char c)
{
	char	**res;
	int		idx;
	int		res_idx;

	res = (char **)malloc((get_word_cnt(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	idx = -1;
	res_idx = 0;
	while (s[++idx] != '\0')
	{
		if (s[idx] != c)
			res[res_idx++] = get_word(s, c, &idx);
	}
	res[res_idx] = NULL;
	return (res);
}