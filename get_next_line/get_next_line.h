/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:40 by geshin            #+#    #+#             */
/*   Updated: 2023/03/28 16:19:16 by geshin           ###   ########.fr       */
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

t_node	*ft_get_line_lst(fd);
int		ft_get_node_cnt(t_node* head);
void	ft_lstadd_back(t_node **lst, t_node* new);
void	ft_lstclear(t_node **lst);	


#endif