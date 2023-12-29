/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:57:22 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/21 14:50:24 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>

size_t	gnl_strlen(const char *s);
char	*gnl_strdup(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char const *s, size_t start, size_t len, size_t s_size);
char	*get_next_line(int fd);

char	**ft_split(char const *s, char sp);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(const char *str, int fd);

double	ft_atod(const char *str);

char	*ft_revstr(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif