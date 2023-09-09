/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:08:38 by geshin            #+#    #+#             */
/*   Updated: 2023/06/09 16:11:40 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

typedef struct s_list
{
	int				text_len;
	int				is_eol;
	char			*text;
	struct s_list	*next;
}	t_list;

char	*str_substr(char *s, int sidx, int len);
void	str_strncat(char *s, int len, t_list *node);
t_list	*lst_create_node(char *text, int len, int is_eol);
void	lst_push_back(t_list **head, t_list **tail, t_list *node);
void	lst_pop_front(t_list **head, t_list **tail);

char	*get_next_line(int fd);

#endif