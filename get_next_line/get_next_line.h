/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:40 by geshin            #+#    #+#             */
/*   Updated: 2023/03/27 17:52:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

typedef struct s_node
{
	int 			fd;
	char			*content;
	struct s_node	*next;
}	t_node;

char		*get_next_line(int fd);

static t_node	*ft_get_line_lst(fd);
static int		ft_get_node_cnt(t_node* head);
static void		ft_lstadd_back(t_node **lst, t_node* new);
static void		ft_lstclear(t_node **lst);	


#endif