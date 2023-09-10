/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:44:26 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 12:51:19 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	*get_next_line(int fd);
int		ft_atoi(const char *s);
int		ft_strlen(char *s);
int		ft_ptrlen(char **p);
char	**ft_split(char const *s, char c);

#endif