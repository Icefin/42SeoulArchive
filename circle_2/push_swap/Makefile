#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

INCLUDE = includes/
BONUS_FLAG = FALSE

#Libraries=====================================================================
PRINTF = ft_printf/libftprintf.a

#Sources========================================================================
SRCS = ./srcs/push_swap.c \
		./srcs/displayer.c \
		./srcs/parser.c \
		./srcs/commands_1.c \
		./srcs/commands_2.c \
		./srcs/rstack_1.c \
		./srcs/rstack_2.c \
		./srcs/sorter_1.c \
		./srcs/sorter_2.c \
		./srcs/sorter_3.c \
		./srcs/sorter_4.c \
		./srcs/utils_1.c \
		./srcs/utils_2.c \
		./srcs/vector_1.c \
		./srcs/vector_2.c


SRCS_BONUS = ./bonus/checker_bonus.c

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

$(NAME) : $(OBJS) $(PRINTF)
	$(CC) -o $(NAME) -Lft_printf -lftprintf $(OBJS)

$(NAME_BONUS) : $(OBJS_BONUS) $(PRINTF)
	$(CC) -o $(NAME_BONUS) -Lft_printf -lftprintf $(OBJS_BONUS)

$(PRINTF) :
	make -C ft_printf

%.o : %.c
	$(CC) -I$(INCLUDE) -c $< -o $@

clean :
	make fclean -C ft_printf
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
