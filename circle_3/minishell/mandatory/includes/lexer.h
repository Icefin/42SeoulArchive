/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 16:54:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "queue_token.h"

/*
** Tokenize input command
** Can Tokenize : return TRUE(1)
** Cannot Tokenize : return FALSE(0)
*/
int	lexer_tokenize_command(char *command, t_queue_token *out);

#endif

/*
```
%token		WORD

%token		SLESS		SGREAT
		'<'		'>'
%token		DLESS		DGREAT
		'<<'		'>>'
%token		PIPE
		'|'
```

1. If the end of input is recognized,
 the current token (if any) shall be delimited.

2. If the previous character was used as part of an operator and the current character is not quoted and can be used with the previous characters to form an operator,
 it shall be used as part of that (operator) token.

3. If the previous character was used as part of an operator and the current character cannot be used with the previous characters to form an operator,
 the operator containing the previous character shall be delimited.

4. If the current character is single-quote, or double-quote and it is not quoted,
 it shall affect quoting for subsequent characters up to the end of the quoted text. The rules for quoting are as described in Quoting. During token recognition, no substitutions shall be actually performed, and the result token shall contain exactly the characters that appear in the input, unmodified, including any embedded or enclosing quotes or substitution operators, between the quotation-mark and the end of the quoted text. The token shall not be delimited by the end of the quoted field.

5. If the current character is an unquoted '$',
 the shell shall identify the start of parameter expansion. The shell shall read sufficient input to determine the end of the unit to be expanded.

6. If the current character is not quoted and can be used as the first character of a new operator,
 the current token (if any) shall be delimited. The current character shall be used as the beginning of the next (operator) token.

7. If the current character is an unquoted <blank>,
 any token containing the previous character is delimited and the current character shall be discarded.

8. If the previous character was part of a word,
 the current character shall be appended to that word.

9. The current character is used as the start of a new word.

*/