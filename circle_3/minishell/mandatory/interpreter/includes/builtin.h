/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:06 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:12 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"
# include "map_environment.h"

int		execute_echo(t_command *cmd);
int		execute_cd(t_command *cmd, t_map_env *menv);
int		execute_pwd(void);
int		execute_export(t_command *cmd, t_map_env *menv);
int		execute_unset(t_command *cmd, t_map_env *menv);
int		execute_env(t_map_env *menv);
int		execute_exit(void);

#endif