/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:05:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/29 17:04:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

int			ft_strlen(char *s);
int			ft_arrlen(char **arr);
void		destroy_2d_array(char **arr);
long long	ft_stoi_plus_imax(char *s);
char 		**ft_split(char *s, char sep);


#endif