/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:46:22 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/28 22:04:46 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, int len);
void	ft_putstr_fd(char *c, int fd);

char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_with_char(char *s1, char *s2, char c);

char	**ft_split(char const *s, char c);

#endif