/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:04:03 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/16 15:25:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "commontype_bonus.h"

char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int num);
int		ft_atoi(char *s);
t_int64	get_time(void);

#endif