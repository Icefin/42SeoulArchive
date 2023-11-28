/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:03:48 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:04:08 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_total_words_cnt(char const *s, char c)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == 0))
			cnt++;
		idx++;
	}
	return (cnt);
}

static int	*ft_get_each_words_len(char const *s, char c, int words_cnt)
{
	int	*words_len;
	int	s_idx;
	int	w_idx;

	words_len = (int *)malloc(sizeof(int) * words_cnt);
	if (!words_len)
		return (NULL);
	w_idx = 0;
	while (w_idx < words_cnt)
		words_len[w_idx++] = 0;
	w_idx = 0;
	s_idx = 0;
	while (s[s_idx])
	{
		if (s[s_idx] != c)
		{
			words_len[w_idx]++;
			if (s[s_idx + 1] == c || s[s_idx + 1] == 0)
				w_idx++;
		}
		s_idx++;
	}
	return (words_len);
}

static int	ft_make_words_arr(char **words_arr, int *words_len, int words_cnt)
{
	int	idx;

	idx = 0;
	while (idx < words_cnt)
	{
		words_arr[idx] = (char *)malloc(sizeof(char) * ((words_len)[idx] + 1));
		if (!words_arr[idx])
		{
			idx = 0;
			while (words_arr[idx])
				free(words_arr[idx++]);
			free(words_len);
			return (0);
		}
		idx++;
	}
	free(words_len);
	return (1);
}

static void	ft_split_words(char const *s, char c, char **words_arr)
{
	int	s_idx;
	int	arr_idx;
	int	words_idx;

	s_idx = 0;
	arr_idx = 0;
	words_idx = 0;
	while (s[s_idx])
	{
		if (s[s_idx] != c)
		{
			words_arr[arr_idx][words_idx++] = s[s_idx];
			words_arr[arr_idx][words_idx] = 0;
			if (s[s_idx + 1] == c || s[s_idx + 1] == 0)
			{
				arr_idx++;
				words_idx = 0;
			}
		}
		s_idx++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		words_cnt;
	int		*words_len;
	int		idx;
	char	**words_arr;

	words_cnt = ft_get_total_words_cnt(s, c);
	words_len = ft_get_each_words_len(s, c, words_cnt);
	if (!words_len)
		return (NULL);
	words_arr = (char **)malloc(sizeof(char *) * (words_cnt + 1));
	if (!words_arr)
	{
		free(words_len);
		return (NULL);
	}
	words_arr[words_cnt] = 0;
	idx = ft_make_words_arr(words_arr, words_len, words_cnt);
	if (!idx)
	{
		free(words_arr);
		return (NULL);
	}
	ft_split_words(s, c, words_arr);
	return (words_arr);
}
