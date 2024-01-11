/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:08:12 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/21 14:53:13 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static char	*ft_free(char **save, char *result, char *buf)
{
	if (*save)
	{
		free(*save);
		*save = NULL;
	}
	if (result)
		free(result);
	if (buf)
		free(buf);
	return (NULL);
}

static char	*ft_get_result(char **save, int status)
{
	char	*tmp;
	char	*result;
	char	*buf;
	size_t	size;

	tmp = gnl_strchr(*save, '\n');
	result = NULL;
	if (tmp != NULL)
	{
		size = gnl_strlen(*save);
		result = gnl_substr(*save, 0, tmp - (*save) + 1, size);
		buf = gnl_substr(*save, tmp - (*save) + 1, gnl_strlen(tmp + 1), size);
		if (!result || !buf)
			return (ft_free(save, result, buf));
		free(*save);
		*save = buf;
	}
	else
	{
		if (status == 0 && **save != '\0')
			result = gnl_strdup(*save);
		ft_free(save, NULL, NULL);
	}
	return (result);
}

static int	ft_read_fd(int fd, char **save)
{
	char	*arr;
	int		status;

	arr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (arr == NULL)
		return (-1);
	status = 0;
	while (!gnl_strchr(*save, '\n'))
	{
		status = read(fd, arr, BUFFER_SIZE);
		if (status <= 0)
			break ;
		arr[status] = '\0';
		*save = gnl_strjoin(*save, arr);
		if (!(*save))
		{
			free(arr);
			return (-1);
		}
	}
	free(arr);
	return (status);
}

char	*get_next_line(int fd)
{
	static char	*save;
	int			status;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char));
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	status = ft_read_fd(fd, &save);
	if (status < 0)
		return (ft_free(&save, NULL, NULL));
	return (ft_get_result(&save, status));
}
