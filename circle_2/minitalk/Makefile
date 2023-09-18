#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

#Libraries=====================================================================
LIBFT = libft/libft.a


#Sources========================================================================
SRCSERV = srcs/server.c
SRCCLNT = srcs/client.c




#Objects=========================================================================
OBJSERV = srcs/server.o
OBJCLNT = srcs/client.o




#Rules===========================================================================
all : $(NAME)

$(SERVER) : $(OBJSERV) $(LIBFT)
	$(CC) -o server -Llibft -lft $(OBJSERV)

$(CLIENT) : $(OBJCLNT) $(LIBFT)
	$(CC) -o client -Llibft -lft $(OBJCLNT)

$(LIBFT) :
	make -C libft

$(OBJSERV) : $(SRCSERV)
	$(CC) -c $(CFLAGS) $(SRCSERV)
	mv server.o ./srcs/server.o

$(OBJCLNT) : $(SRCCLNT)
	$(CC) -c $(CFLAGS) $(SRCCLNT)
	mv client.o ./srcs/client.o
clean :
	make fclean -C libft
	rm -rf $(OBJSERV) $(OBJCLNT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
