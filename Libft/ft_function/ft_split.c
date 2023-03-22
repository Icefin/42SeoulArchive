/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:21 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 19:31:28 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_word_cnt(char *s, char c)
{
	int	left;
	int	right;
	int word_cnt;

	left = 0;
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

char	*get_word(char *s, char c)
{
	char	*ptr;
	int		len;

	while (s[len] != c && s[len] != '\0')
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		slen;
	int		i;
	int		res_idx;
	
	res = (char **)malloc((get_word_cnt(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	res_idx = 0;
	while (i < slen)
	{
		if (s[i] != c)
		{
			res[res_idx] = get_word(&s[i], c);
			if (res[res_idx] == NULL)
				return (NULL);
			res_idx++;
		}
		i++;
	}
	res[res_idx] = NULL;
	return (res);
}