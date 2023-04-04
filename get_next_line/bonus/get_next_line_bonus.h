/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:40 by geshin            #+#    #+#             */
/*   Updated: 2023/03/29 18:45:26 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				text_len;
	char			*text;
	struct s_list	*next;
}	t_list;

char			*get_next_line(int fd);

t_list			*ft_lstnew(char *text, int len);
void			ft_lst_node_add_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);	
char			*ft_strdup(const char *src, int srclen);
void			ft_strmove(char *dst, const char *src, int len);

#endif