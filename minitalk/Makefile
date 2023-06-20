#Flags========================================================================
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
AFLAGS = -rcs

NAME = minitalk
CLIENT = client
SERVER = server
INC = includes/

#Libraries=====================================================================
LIB_LIB = libft

LIBFT = libft/libft.a


#Sources========================================================================
SRCS = client.c \
		server.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	make fclean -C libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
