#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

PROGRAM = server client

#Libraries=====================================================================
LIBFT = libft/libft.a


#Sources========================================================================
SRCS = srcs/server.c \
		srcs/client.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(PROGRAM)

server : server.o $(LIBFT)
	$(CC) -o server -Llibft -lft server.o

client : client.o $(LIBFT)
	$(CC) -o client -Llibft -lft client.o

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