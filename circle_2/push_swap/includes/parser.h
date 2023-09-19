/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:24:11 by geshin            #+#    #+#             */
/*   Updated: 2023/09/19 14:25:29 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Parse argv[2] to stack
//First element of argv must be located at the top of stack

//Error case :
//1) Not integer
//2) Overflow
//3) Duplicated value

#ifndef PARSER_H
# define PARSER_H

typedef struct s_parser
{
	char *argument;
} t_parser;



#endif