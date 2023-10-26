/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:05:12 by geshin            #+#    #+#             */
/*   Updated: 2023/10/26 18:23:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_TYPE_H
# define NODE_TYPE_H

typedef enum e_node_type
{
	CMD_NAME,
	CMD_WORD,
	FILENAME,
	HERE_END,

	IO_FILE,
	IO_HERE,
	IO_REDIRECT,
	
	CMD_PREFIX,
	CMD_SUFFIX,
	SIMPLE_COMMAND,
	PIPE_SEQUENCE
}	t_node_type;

typedef struct s_ast_node
{
	t_node_type		type;
	
	//...

	t_ast_node		*left;
	t_ast_node		*right;
}	t_ast_node;

#endif