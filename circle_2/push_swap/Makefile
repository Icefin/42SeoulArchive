#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

#Libraries=====================================================================
LIBFT = libft/libft.a


#Sources========================================================================
SRCS = 



#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(NAME)

$(LIBFT) :
	make -C libft

.c.o :
	$(CC) -c $(CFLAGS) $?

clean :
	make fclean -C libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(PROGRAM)

re : fclean all

.PHONY : all clean fclean re
