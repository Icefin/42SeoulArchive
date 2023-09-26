#Flags========================================================================
CC = cc
CFLAGS = -Wall -Wextra -Werror

BONUS_FLAG = FALSE

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

NAME = $(SERVER) $(CLIENT)
NAME_BONUS = $(SERVER_BONUS) $(CLIENT_BONUS)

ifeq ($(BONUS_FLAG),TRUE)
	SERVER = $(SERVER_BONUS)
	CLIENT = $(CLIENT_BONUS)
	NAME = $(NAME_BONUS)
endif

#Libraries=====================================================================
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a


#Sources========================================================================
SRCSERV = srcs/server.c
SRCCLNT = srcs/client.c

SRCSERV_BONUS = srcs/server_bonus.c
SRCCLNT_BONUS = srcs/client_bonus.c

ifeq ($(BONUS_FLAG),TRUE)
	SRCSERV = $(SRCSERV_BONUS)
	SRCCLNT = $(SRCCLNT_BONUS)
endif

#Objects=========================================================================
OBJSERV = objs/server.o
OBJCLNT = objs/client.o

OBJSERV_BONUS = objs/server_bonus.o
OBJCLNT_BONUS = objs/client_bonus.o

ifeq ($(BONUS_FLAG),TRUE)
	OBJSERV = $(OBJSERV_BONUS)
	OBJCLNT = $(OBJCLNT_BONUS)
endif

#Rules===========================================================================
all : $(NAME)

$(SERVER) : $(OBJSERV) $(PRINTF) $(LIBFT)
	$(CC) -Llibft -lft -Lft_printf -lftprintf $(OBJSERV) -o $(SERVER) 

$(CLIENT) : $(OBJCLNT) $(PRINTF) $(LIBFT)
	$(CC) -Llibft -lft -Lft_printf -lftprintf $(OBJCLNT) -o $(CLIENT)

$(OBJSERV) :
	$(CC) -c $(CFLAGS) -Ilibft -Ift_printf $(SRCSERV) -o $(OBJSERV)

$(OBJCLNT) :
	$(CC) -c $(CFLAGS) -Ilibft -Ift_printf $(SRCCLNT) -o $(OBJCLNT)

$(LIBFT) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

clean :
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJSERV) $(OBJCLNT) $(OBJSERV_BONUS) $(OBJCLNT_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

bonus : 
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
