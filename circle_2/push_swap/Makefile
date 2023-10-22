#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

INCLUDE = ./mandatory/includes/
INCLUDE_BONUS = ./bonus/includes/
BONUS_FLAG = FALSE

#Libraries=====================================================================


#Sources========================================================================
SRCS = ./mandatory/srcs/push_swap.c \
		./mandatory/srcs/displayer.c \
		./mandatory/srcs/parser.c \
		./mandatory/srcs/commands_1.c \
		./mandatory/srcs/commands_2.c \
		./mandatory/srcs/commands_3.c \
		./mandatory/srcs/rstack_1.c \
		./mandatory/srcs/rstack_2.c \
		./mandatory/srcs/sorter_1.c \
		./mandatory/srcs/sorter_2.c \
		./mandatory/srcs/sorter_3.c \
		./mandatory/srcs/sorter_4.c \
		./mandatory/srcs/utils_1.c \
		./mandatory/srcs/utils_2.c \
		./mandatory/srcs/vector_1.c \
		./mandatory/srcs/vector_2.c


SRCS_BONUS = ./bonus/srcs/checker_bonus.c \
			./bonus/srcs/commands_bonus_1.c \
			./bonus/srcs/commands_bonus_2.c \
			./bonus/srcs/commands_bonus_3.c \
			./bonus/srcs/parser_bonus.c \
			./bonus/srcs/rstack_bonus_1.c \
			./bonus/srcs/rstack_bonus_2.c \
			./bonus/srcs/utils_bonus_1.c \
			./bonus/srcs/utils_bonus_2.c \
			./bonus/srcs/vector_bonus_1.c \
			./bonus/srcs/vector_bonus_2.c

#Objects=========================================================================
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#Rules===========================================================================

ifeq ($(BONUS_FLAG),TRUE)
	TOT_TARGET = $(NAME) $(NAME_BONUS)
else
	TOT_TARGET = $(NAME)
endif

all : $(TOT_TARGET)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_BONUS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
