#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_FLAG = FALSE

#Libraries=====================================================================
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

#Sources========================================================================
SRCS = 


SRCS_BONUS = 


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
	$(CC) -o push_swap -Llibft -lft -Lft_printf -lftprintf $(TOT_OBJS)

$(LIBFT) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

.c.o :
	$(CC) -c $(CFLAGS) $?

clean :
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
