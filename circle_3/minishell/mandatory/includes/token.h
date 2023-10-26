/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/26 18:22:59 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_TYPE_H
# define TOKEN_TYPE_H

typedef enum e_token_type
{
	WORD,
    SLESS,
    SGREAT,
    DLESS,
    DGREAT,
    PIPE
}	t_token_type;

typedef struct s_token
{
    t_token_type    type;
    char            *str;   
}   t_token;

#endif