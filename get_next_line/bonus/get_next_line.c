/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:26 by geshin            #+#    #+#             */
/*   Updated: 2023/04/12 12:48:48 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static int	get_eol_idx(char *buffer, int size)
{
	int	idx;
	
	idx = 0;
	while (idx < size)
	{
		if (buffer[idx] == 'n')
			return (idx);
		idx++;
	}
	return (-1);
}

static void	read_file(int fd, char *res, char *remain, int *rm_size)
{
	char	buffer[BUFFER_SIZE];
	int		eol_idx;
	int		rd_size;

	rd_size = read(fd, buffer, BUFFER_SIZE);
	while (rd_size > 0)
	{
		eol_idx = get_eol_idx(buffer ,rd_size);
		if (eol_idx != -1)
		{
			ft_strncat(res, buffer, eol_idx);
			remain = ft_strdup(&buffer[eol_idx], rd_size - eol_idx);
			rm_size = rd_size - eol_idx;
			return ;
		}
		ft_strncat(res, buffer, rd_size);
		rd_size = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*remain_process(char* remain, int *rm_size)
{
	char	*res;
	char	*tmp;
	int 	eol_idx;

	eol_idx = get_eol_idx(remain, *rm_size);
	if (eol_idx != -1)
	{
		res = ft_strndup(remain, eol_idx + 1);
		*rm_size = *rm_size - (eol_idx + 1);
		tmp = ft_strndup(remain[eol_idx + 1], *rm_size);
		free(remain);
		remain = tmp;
		return (res);	
	}
	res = ft_strndup(remain, *rm_size);
	free(remain);
	*rm_size = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	static int	rm_size;
	char		*res;
	int			eol_idx;

	if (rm_size != 0)
		res = remain_process(remain, &rm_size);
	if (res == NULL || res[rm_size - 1] == '\n')
		return (res);
	read_file(fd, res, remain, &rm_size);
	return (res);
}