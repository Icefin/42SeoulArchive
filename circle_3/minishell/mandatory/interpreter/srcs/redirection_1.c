/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:53:01 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 01:56:55 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "commontype.h"
#include "utils.h"

int	redirection_in(t_string *filename)
{
	int		fd;
	char	*str;

	str = get_string_c_str(filename);
	fd = open(str, O_RDONLY);
	free(str);
	if (fd < 0 || dup2(fd, STDIN_FD) == -1)
	{
		perror("ms ");
		return (1);
	}
	close(fd);
	return (0);
}

int	redirection_out(t_string *filename)
{
	int		fd;
	char	*str;

	str = get_string_c_str(filename);
	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(str);
	if (fd < 0 || dup2(fd, STDOUT_FD) == -1)
	{
		perror("ms");
		return (1);
	}
	close(fd);
	return (0);
}

int	redirection_append(t_string *filename)
{
	int		fd;
	char	*str;

	str = get_string_c_str(filename);
	fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0644);
	free(str);
	if (fd < 0 || dup2(fd, STDOUT_FD) == -1)
	{
		perror("ms");
		return (1);
	}
	close(fd);
	return (0);
}

int	redirection_pipe(int piperead, int pipewrite)
{
	if (piperead != STDIN_FD)
	{
		if (dup2(piperead, STDIN_FD) == -1)
			return (1);
		close(piperead);
	}
	if (pipewrite != STDOUT_FD)
	{
		if (dup2(pipewrite, STDOUT_FD) == -1)
			return (1);
		close(pipewrite);
	}
	return (0);
}
