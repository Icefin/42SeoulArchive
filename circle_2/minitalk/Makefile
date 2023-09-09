#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

PROGRAM = server client

#Libraries=====================================================================
LIBFT = libft/libft.a


#Sources========================================================================
SRCS = srcs/client.c \
		srcs/server.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(PROGRAM)

server : $(LIBFT) server.o
	$(CC) -o server -Llibft -lft server.o

client : $(LIBFT) client.o
	$(CC) -o client -Llibft -lft client.o

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make fclean -C libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(PROGRAM)

re : fclean all