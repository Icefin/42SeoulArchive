/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:05:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/28 14:54:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

long long	ft_atoi_plus_int_max(char *str);
int			ft_strlen(char *str);
char 		**ft_split(char *str, char sep);

#endif