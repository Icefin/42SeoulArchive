/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:02:50 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:21:02 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "commontype.h"
#include "map_environment.h"
#include "redirection.h"
#include "utils.h"

#define LOOP_SIZE 1000

extern void	expand_parameter(t_map_env *menv, t_string *out);
extern void	ft_signal_heredoc(int signum);
extern void	init_signal(void);

char	*make_heredoc_tmp_file(void)
{
	t_string	str;
	int			idx;
	char		*tmp;

	idx = -1;
	while (++idx < LOOP_SIZE)
	{
		string_constructor(&str, "/tmp/ms_heredoc_");
		string_append_char(&str, idx / 1000 + '0');
		string_append_char(&str, idx / 100 + '0');
		string_append_char(&str, idx / 10 + '0');
		string_append_char(&str, idx % 10 + '0');
		tmp = get_string_c_str(&str);
		string_destructor(&str);
		if (access(tmp, F_OK) == -1)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

static int	read_heredoc(t_map_env *menv, int write_fd, t_string *delimeter)
{
	char		*input;
	char		*end_word;
	char		*tmp;
	t_string	str;

	end_word = get_string_c_str(delimeter);
	while (TRUE)
	{
		input = readline("heredoc> ");
		if (input == NULL || ft_strcmp(input, end_word) == 0)
		{
			if (input != NULL)
				free(input);
			free(end_word);
			exit(0);
		}
		string_constructor(&str, input);
		free(input);
		expand_parameter(menv, &str);
		tmp = get_string_c_str(&str);
		string_destructor(&str);
		write(write_fd, tmp, ft_strlen(tmp));
		write(write_fd, "\n", 1);
		free(tmp);
	}
}

char	*make_and_open_tmp_file(int *fd)
{
	char	*tmp_file;

	tmp_file = make_heredoc_tmp_file();
	*fd = open(tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fd < 0)
	{
		free(tmp_file);
		return (NULL);
	}
	return (tmp_file);
}

int	handle_heredoc(t_map_env *menv, t_string *delimeter)
{
	int		fd;
	int		status;
	char	*tmp_file;
	pid_t	pid;

	tmp_file = make_and_open_tmp_file(&fd);
	if (tmp_file == NULL)
		return (1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, ft_signal_heredoc);
		rl_catch_signals = 1;
		read_heredoc(menv, fd, delimeter);
	}
	waitpid(pid, &status, 0);
	init_signal();
	string_destructor(delimeter);
	string_constructor(delimeter, tmp_file);
	free(tmp_file);
	return (status);
}

int	redirection_heredoc(t_string *filename)
{
	int		fd;
	char	*str;

	str = get_string_c_str(filename);
	fd = open(str, O_RDONLY);
	unlink(str);
	free(str);
	if (fd < 0 || dup2(fd, STDIN_FD) == -1)
	{
		perror("ms");
		return (1);
	}
	close(fd);
	return (0);
}
