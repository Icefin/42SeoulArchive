/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:36:32 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:05:25 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATON_H
# define AUTOMATON_H

# include "vector_token.h"
# include "astree.h"
# include "stack.h"

# define STATE_0	0
# define STATE_1	1
# define STATE_2	2
# define STATE_3	3
# define STATE_4	4
# define STATE_5	5
# define STATE_6	6
# define STATE_7	7
# define STATE_8	8
# define STATE_9	9
# define STATE_10	10
# define STATE_11	11
# define STATE_12	12
# define STATE_13	13
# define STATE_14	14
# define STATE_15	15
# define STATE_16	16
# define STATE_17	17
# define STATE_18	18
# define STATE_19	19
# define STATE_20	20
# define STATE_21	21
# define STATE_22	22
# define STATE_23	23
# define STATE_24	24
# define STATE_25	25
# define STATE_26	26
# define STATE_27	27
# define STATE_28	28
# define STATE_29	29
# define STATE_30	30
# define STATE_PREV	31

# define SHIFT		0
# define REDUCE		1
# define GOTO		2
# define ACCEPT		3

# define PTABLE_ROW 100
# define PTABLE_COL 6

static const int	g_ptable[PTABLE_ROW][PTABLE_COL] = {
{STATE_0,   CMD_NAME,       GOTO,   STATE_6,    0,  DEFAULT},
{STATE_0,   IO_FILE,        GOTO,   STATE_7,    0,  DEFAULT},
{STATE_0,   IO_HERE,        GOTO,   STATE_8,    0,  DEFAULT},
{STATE_0,   IO_REDIRECT,    GOTO,   STATE_9,    0,  DEFAULT},
{STATE_0,   CMD_PREFIX,     GOTO,   STATE_10,   0,  DEFAULT},
{STATE_0,   SIMPLE_COMMAND, GOTO,   STATE_11,   0,  DEFAULT},
{STATE_0,   PIPE_SEQUENCE,  GOTO,   STATE_12,   0,  DEFAULT},
{STATE_0,   WORD,           SHIFT,  STATE_1,    0,  DEFAULT},
{STATE_0,   SLESS,          SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_0,   SGREAT,         SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_0,	DLESS,			SHIFT,	STATE_4,	0,	DEFAULT},
{STATE_0,   DGREAT,			SHIFT,	STATE_5,	0,	DEFAULT},
{STATE_1,   DEFAULT,		REDUCE,	STATE_PREV,	1,	CMD_NAME},
{STATE_2,   FILE_NAME,	    GOTO,   STATE_14,   0,  DEFAULT},
{STATE_2,   WORD,		    SHIFT,  STATE_13,   0,  DEFAULT},
{STATE_3,   FILE_NAME,	    GOTO,   STATE_15,   0,  DEFAULT},
{STATE_3,   WORD,		    SHIFT,  STATE_13,   0,  DEFAULT},
{STATE_4,   HERE_END,	    GOTO,   STATE_17,   0,  DEFAULT},
{STATE_4,   WORD,		    SHIFT,  STATE_16,   0,  DEFAULT},
{STATE_5,   FILE_NAME,	    GOTO,   STATE_18,   0,  DEFAULT},
{STATE_5,   WORD,		    SHIFT,  STATE_13,   0,  DEFAULT},
{STATE_6,   IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_6,   IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_6,   IO_REDIRECT,    GOTO,   STATE_20,   0,  DEFAULT},
{STATE_6,   CMD_SUFFIX,	    GOTO,   STATE_21,   0,  DEFAULT},
{STATE_6,   WORD,		    SHIFT,  STATE_19,   0,  DEFAULT},
{STATE_6,   SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_6,   SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_6,   DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_6,   DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_6,   DEFAULT,	    REDUCE, STATE_PREV, 1,  SIMPLE_COMMAND},
{STATE_7,   DEFAULT,	    REDUCE, STATE_PREV, 1,  IO_REDIRECT},
{STATE_8,   DEFAULT,	    REDUCE, STATE_PREV, 1,  IO_REDIRECT},
{STATE_9,   DEFAULT,	    REDUCE, STATE_PREV, 1,  CMD_PREFIX},
{STATE_10,  CMD_WORD,	    GOTO,   STATE_23,   0,  DEFAULT},
{STATE_10,  IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_10,  IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_10,  IO_REDIRECT,    GOTO,   STATE_24,   0,  DEFAULT},
{STATE_10,  WORD,		    SHIFT,  STATE_22,   0,  DEFAULT},
{STATE_10,  SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_10,  SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_10,  DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_10,  DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_10,  DEFAULT,	    REDUCE, STATE_PREV, 1,  SIMPLE_COMMAND},
{STATE_11,  DEFAULT,	    REDUCE, STATE_PREV, 1,  PIPE_SEQUENCE},
{STATE_12,  PIPE,		    SHIFT,  STATE_26,   0,  DEFAULT},
{STATE_12,  END,		    GOTO,   STATE_25,   0,  DEFAULT},
{STATE_13,  DEFAULT,	    REDUCE, STATE_PREV, 1,  FILE_NAME},
{STATE_14,  DEFAULT,	    REDUCE, STATE_PREV, 2,  IO_FILE},
{STATE_15,  DEFAULT,	    REDUCE, STATE_PREV, 2,  IO_FILE},
{STATE_16,  DEFAULT,	    REDUCE, STATE_PREV, 1,  HERE_END},
{STATE_17,  DEFAULT,	    REDUCE, STATE_PREV, 2,  IO_HERE},
{STATE_18,  DEFAULT,	    REDUCE, STATE_PREV, 2,  IO_FILE},
{STATE_19,  DEFAULT,	    REDUCE, STATE_PREV, 1,  CMD_SUFFIX},
{STATE_20,  DEFAULT,	    REDUCE, STATE_PREV, 1,  CMD_SUFFIX},
{STATE_21,  IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_21,  IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_21,  IO_REDIRECT,    GOTO,   STATE_28,   0,  DEFAULT},
{STATE_21,  WORD,		    SHIFT,  STATE_27,   0,  DEFAULT},
{STATE_21,  SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_21,  SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_21,  DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_21,  DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_21,  DEFAULT,	    REDUCE, STATE_PREV, 2,  SIMPLE_COMMAND},
{STATE_22,  DEFAULT,	    REDUCE, STATE_PREV, 1,  CMD_WORD},
{STATE_23,  IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_23,  IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_23,  IO_REDIRECT,    GOTO,   STATE_20,   0,  DEFAULT},
{STATE_23,  CMD_SUFFIX,	    GOTO,   STATE_29,   0,  DEFAULT},
{STATE_23,  WORD,		    SHIFT,  STATE_19,   0,  DEFAULT},
{STATE_23,  SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_23,  SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_23,  DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_23,  DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_23,  DEFAULT,	    REDUCE, STATE_PREV, 2,  SIMPLE_COMMAND},
{STATE_24,  DEFAULT,	    REDUCE, STATE_PREV, 2,  CMD_PREFIX},
{STATE_25,  DEFAULT,	    ACCEPT, STATE_25,   0,  DEFAULT},
{STATE_26,  CMD_NAME,	    GOTO,   STATE_6,    0,  DEFAULT},
{STATE_26,  IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_26,  IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_26,  IO_REDIRECT,    GOTO,   STATE_9,    0,  DEFAULT},
{STATE_26,  CMD_PREFIX,	    GOTO,   STATE_10,   0,  DEFAULT},
{STATE_26,  SIMPLE_COMMAND, GOTO,   STATE_30,   0,  DEFAULT},
{STATE_26,  WORD,		    SHIFT,  STATE_1,    0,  DEFAULT},
{STATE_26,  SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_26,  SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_26,  DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_26,  DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_27,  DEFAULT,	    REDUCE, STATE_PREV, 2,  CMD_SUFFIX},
{STATE_28,  DEFAULT,	    REDUCE, STATE_PREV, 2,  CMD_SUFFIX},
{STATE_29,  IO_FILE,	    GOTO,   STATE_7,    0,  DEFAULT},
{STATE_29,  IO_HERE,	    GOTO,   STATE_8,    0,  DEFAULT},
{STATE_29,  IO_REDIRECT,    GOTO,   STATE_28,   0,  DEFAULT},
{STATE_29,  WORD,		    SHIFT,  STATE_27,   0,  DEFAULT},
{STATE_29,  SLESS,		    SHIFT,  STATE_2,    0,  DEFAULT},
{STATE_29,  SGREAT,		    SHIFT,  STATE_3,    0,  DEFAULT},
{STATE_29,  DLESS,		    SHIFT,  STATE_4,    0,  DEFAULT},
{STATE_29,  DGREAT,		    SHIFT,  STATE_5,    0,  DEFAULT},
{STATE_29,  DEFAULT,	    REDUCE, STATE_PREV, 3,  SIMPLE_COMMAND},
{STATE_30,  DEFAULT,	    REDUCE, STATE_PREV, 3,  PIPE_SEQUENCE}
};

typedef struct s_automaton
{
	t_stack	st_node;
	t_stack	st_state;
	t_bool	is_enter;
}	t_automaton;

void	automaton_constructor(t_automaton *out);
void	automaton_destructor(t_automaton *atm);

void	automaton_process(t_automaton *atm, t_vector_token *v);
void	automaton_get_result(t_automaton *atm, t_node **out);

#endif
