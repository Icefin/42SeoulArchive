/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:43:54 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/21 14:49:53 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	idx;

	srclen = ft_strlen(src);
	idx = 0;
	while (src[idx] && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (srclen);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	idx;

	if (s1 == NULL || s2 == NULL)
		return (1);
	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && (s1[idx] == s2[idx]))
		++idx;
	return (s1[idx] - s2[idx]);
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		write(fd, &str[idx++], 1);
}
