/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:39:37 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/10 22:39:20 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define STDIN_FD 0
# define STDOUT_FD 1

# include "vector_string.h"

typedef struct s_command
{
	int				argc;
	char			**argv;
	int				stdin_fd;
	int				stdout_fd;
	t_vector_string	vargs;
}	t_command;

void	command_constructor(t_command *out);
void	command_destructor(t_command *cmd);

#endif