#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

INCLUDE = includes/
BONUS_FLAG = FALSE

#Libraries=====================================================================
#LIBFT = libft/libft.a
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


SRCS_BONUS = 

TOT_SRCS = 

#Objects=========================================================================
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TOT_OBJS = 

#Rules===========================================================================

ifeq ($(BONUS_FLAG),TRUE)
	TOT_OBJS = $(OBJS) $(OBJS_BONUS)
else
	TOT_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(TOT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) -o push_swap -Lft_printf -lftprintf $(TOT_OBJS)

#$(LIBFT) :
#	make -C libft

$(PRINTF) :
	make -C ft_printf

%.o : %.c
	$(CC) -I$(INCLUDE) -c $< -o $@

clean :
#	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
