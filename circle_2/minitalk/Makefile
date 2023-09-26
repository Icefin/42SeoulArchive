#Flags========================================================================
CC = cc
CFLAGS = -Wall -Wextra -Werror

BONUS_FLAG = FALSE

SERVER = server
CLIENT = client

NAME = $(SERVER) $(CLIENT)

#Libraries=====================================================================
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a


#Sources========================================================================
SRCSERV = srcs/server.c
SRCSERVB = srcs/server_bonus.c

SRCCLNT = srcs/client.c
SRCCLNTB = srcs/client_bonus.c

ifeq ($(BONUS_FLAG),TRUE)
	SRCSERVT = $(SRCSERVB)
	SRCCLNTT = $(SRCCLNTB)
else
	SRCSERVT = $(SRCSERV)
	SRCCLNTT = $(SRCCLNT)
endif


#Objects=========================================================================
OBJSERV = objs/server.o
OBJSERVB = objs/server_bonus.o

OBJCLNT = objs/client.o
OBJCLNTB = objs/client_bonus.o

ifeq ($(BONUS_FLAG),TRUE)
	OBJSERVT = $(OBJSERVB)
	OBJCLNTT = $(OBJCLNTB)
else
	OBJSERVT = $(OBJSERV)
	OBJCLNTT = $(OBJCLNT)
endif


#Rules===========================================================================
all : $(NAME)

$(SERVER) : $(OBJSERVT) $(PRINTF) $(LIBFT)
	$(CC) -Llibft -lft -Lft_printf -lftprintf $(OBJSERVT) -o $(SERVER) 

$(OBJSERVT) :
	$(CC) -c $(CFLAGS) -Ilibft -Ift_printf $(SRCSERVT) -o $(OBJSERVT)

$(CLIENT) : $(OBJCLNTT) $(PRINTF) $(LIBFT)
	$(CC) -Llibft -lft -Lft_printf -lftprintf $(OBJCLNTT) -o $(CLIENT)

$(OBJCLNTT) :
	$(CC) -c $(CFLAGS) -Ilibft -Ift_printf $(SRCCLNTT) -o $(OBJCLNTT)

$(LIBFT) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

clean :
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJSERV) $(OBJCLNT) $(OBJSERVB) $(OBJCLNTB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : 
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
