/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:02:34 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 17:51:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Instructions must be separated by a '\n' and nothing else

#ifndef DISPLAYER_H
# define DISPLAYER_H

#include "commands.h"
#include "vector.h"

#include <stdio.h>

void	display_commands(t_vector *commands);

#endif