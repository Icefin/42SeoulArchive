/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:25 by geshin            #+#    #+#             */
/*   Updated: 2023/03/28 17:58:31 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	t_node	*line;
	char	*buffer;
	int		lst_node_cnt;

	line = ft_get_line_lst(fd);
	lst_node_cnt = ft_get_node_cnt(line);
	
	buffer = (char *)malloc(BUFFER_SIZE * (lst_node_cnt - 1) + last_str_len + 1);
	ft_lstclear(&line);
	return (buffer);
}