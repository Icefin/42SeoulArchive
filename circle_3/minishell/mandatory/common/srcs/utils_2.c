/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:11:51 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:04:54 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		idx;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && (s1[idx] == s2[idx]))
		++idx;
	return (s1[idx] - s2[idx]);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	idx;

	idx = 0;
	while ((s1[idx] || s2[idx]) && idx < n)
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		idx_to;
	int		idx_from;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	idx_to = 0;
	idx_from = 0;
	while (s1[idx_from])
		str[idx_to++] = s1[idx_from++];
	idx_from = 0;
	while (s2[idx_from])
		str[idx_to++] = s2[idx_from++];
	str[idx_to] = '\0';
	return (str);
}

char	*ft_strjoin_with_char(char *s1, char *s2, char c)
{
	char	*str;
	int		idx_to;
	int		idx_from;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	idx_to = 0;
	idx_from = 0;
	while (s1[idx_from])
		str[idx_to++] = s1[idx_from++];
	str[idx_to++] = c;
	idx_from = 0;
	while (s2[idx_from])
		str[idx_to++] = s2[idx_from++];
	str[idx_to] = '\0';
	return (str);
}
