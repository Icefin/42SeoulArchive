/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:36:40 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 01:45:50 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "command.h"
# include "string.h"

int	redirection_in(t_string *filename);
int	redirection_out(t_string *filename);
int	redirection_append(t_string *filename);
int	redirection_heredoc(t_string *filename);
int	redirection_pipe(int piperead, int pipewrite);

#endif