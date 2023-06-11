/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:44:26 by geshin            #+#    #+#             */
/*   Updated: 2023/06/11 20:04:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	*get_next_line(int fd);
int		ft_getnbr(char *s);
int		ft_strlen(char *s);
char	**ft_split(char const *s, char c);

#endif