/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:05:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 16:40:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

#include <stdlib.h>

#define FALSE	0
#define TRUE	1

int			ft_strlen(char *s);
int			ft_arrlen(char **arr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		destroy_2d_array(char **arr);
long long	ft_stoi_plus_imax(char *s);
char 		**ft_split(char *s, char sep);


#endif