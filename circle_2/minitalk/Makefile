#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

#Libraries=====================================================================
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a



#Sources========================================================================
SRCSERV = srcs/server.c
SRCCLNT = srcs/client.c




#Objects=========================================================================
OBJSERV = srcs/server.o
OBJCLNT = srcs/client.o




#Rules===========================================================================
all : $(NAME)

$(SERVER) : $(OBJSERV) $(PRINTF)
	$(CC) -o server -Lft_printf -lftprintf $(OBJSERV)

$(OBJSERV) : $(SRCSERV)
	$(CC) -c $(CFLAGS) -Ift_printf $(SRCSERV)
	mv server.o ./srcs/server.o

$(CLIENT) : $(OBJCLNT) $(LIBFT)
	$(CC) -o client -Llibft -lft $(OBJCLNT)

$(OBJCLNT) : $(SRCCLNT)
	$(CC) -c $(CFLAGS) -Ilibft $(SRCCLNT)
	mv client.o ./srcs/client.o

$(LIBFT) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

clean :
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJSERV) $(OBJCLNT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
