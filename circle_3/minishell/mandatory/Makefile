# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 13:43:41 by jihwjeon          #+#    #+#              #
#    Updated: 2023/11/29 03:48:14 by jihwjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

DIR_COMMON_SRCS		=	./common/srcs
SRCS_COMMON			=	\
						astree.c \
						map_environment_1.c \
						map_environment_2.c \
						minishell.c \
						string_1.c \
						string_2.c \
						token.c \
						utils_1.c \
						utils_2.c \
						utils_3.c \
						vector_string_1.c \
						vector_string_2.c \
						vector_token_1.c \
						vector_token_2.c \

DIR_INTERPRETER_SRCS		=	interpreter/srcs
SRCS_INTERPRETER			=	\
								builtin_1.c \
								builtin_2.c \
								builtin_3.c \
								builtin_4.c \
								command_1.c \
								command_2.c \
								command_3.c \
								interpreter_1.c \
								interpreter_2.c \
								redirection_1.c \
								redirection_2.c \
								signal.c \

DIR_LEXER_SRCS		=	./lexer/srcs
SRCS_LEXER			=	\
						lexer_1.c \
						lexer_2.c \
						lexer_3.c \
						lexer_4.c \
						lexer_5.c \

DIR_PARSER_SRCS		=	./parser/srcs
SRCS_PARSER			=	\
						automaton_1.c \
						automaton_2.c \
						automaton_3.c \
						automaton_4.c \
						automaton_5.c \
						parser.c \
						stack_1.c \
						stack_2.c \
						stack_3.c \
						
DIR_COMMON_OBJS		=	./common/objs
PATH_COMMON_OBJS	:=	$(addprefix $(DIR_COMMON_OBJS)/, $(SRCS_COMMON:.c=.o))

DIR_INTERPRETER_OBJS	=	./interpreter/objs
PATH_INTERPRETER_OBJS	:=	$(addprefix $(DIR_INTERPRETER_OBJS)/, $(SRCS_INTERPRETER:.c=.o))

DIR_LEXER_OBJS		=	./lexer/objs
PATH_LEXER_OBJS		:=	$(addprefix $(DIR_LEXER_OBJS)/, $(SRCS_LEXER:.c=.o))

DIR_PARSER_OBJS		=	./parser/objs
PATH_PARSER_OBJS	:=	$(addprefix $(DIR_PARSER_OBJS)/, $(SRCS_PARSER:.c=.o))

OBJS_ALL			:=	 \
						$(PATH_COMMON_OBJS) \
						$(PATH_LEXER_OBJS) \
						$(PATH_INTERPRETER_OBJS) \
						$(PATH_PARSER_OBJS) \

DIR_INCLUDES		:= $(wildcard */includes)
PARAM_INCLUDES		:= $(addprefix -I, $(DIR_INCLUDES))

CC		=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g3 $(PARAM_INCLUDES)
LFLAGS	:=	-lreadline
	
.PHONY: all clean fclean re

all		: $(NAME)

clean	:
	rm -rf $(DIR_COMMON_OBJS)
	rm -rf $(DIR_INTERPRETER_OBJS)
	rm -rf $(DIR_LEXER_OBJS)
	rm -rf $(DIR_PARSER_OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: 
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS_ALL)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

$(DIR_COMMON_OBJS)/%.o	:	$(DIR_COMMON_SRCS)/%.c| $(DIR_COMMON_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ 
	
$(DIR_INTERPRETER_OBJS)/%.o	:	$(DIR_INTERPRETER_SRCS)/%.c | $(DIR_INTERPRETER_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(DIR_LEXER_OBJS)/%.o	:	$(DIR_LEXER_SRCS)/%.c | $(DIR_LEXER_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_PARSER_OBJS)/%.o	:	$(DIR_PARSER_SRCS)/%.c | $(DIR_PARSER_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(DIR_COMMON_OBJS)	:
	mkdir $(DIR_COMMON_OBJS)

$(DIR_INTERPRETER_OBJS) :
	mkdir $(DIR_INTERPRETER_OBJS)

$(DIR_LEXER_OBJS) :
	mkdir $(DIR_LEXER_OBJS)
	
$(DIR_PARSER_OBJS) :
	mkdir $(DIR_PARSER_OBJS)