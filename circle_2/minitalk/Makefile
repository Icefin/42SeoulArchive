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
SRCCLNT = srcs/client.c

SRCSERVB = srcs/server_bonus.c
SRCCLNTB = srcs/client_bonus.c

ifeq ($(BONUS_FLAG),TRUE)
	SRCSERVT = SRCSERV
	SRCCLNTT = SRCCLNT
else
	SRCSERVT = SRCSERVB
	SRCCLNTT = SRCCLNTB
endif

#Objects=========================================================================
OBJSERV = srcs/server.o
OBJCLNT = srcs/client.o

OBJSERVB = srcs/server_bonus.o
OBJCLNTB = srcs/client_bonus.o

ifeq ($(BONUS_FLAG),TRUE)
	OBJSERVT = OBJSERV
	OBJCLNTT = OBJCLNT
else
	OBJSERVT = OBJSERVB
	OBJCLNTT = OBJCLNTB
endif


#Rules===========================================================================
all : $(NAME)

$(SERVER) : $(OBJSERVT) $(PRINTF)
	$(CC) -o server -Lft_printf -lftprintf $(OBJSERVT)

$(OBJSERVT) : $(SRCSERVT)
	$(CC) -c $(CFLAGS) -Ift_printf $(SRCSERVT)
	mv server.o ./srcs/server.o

$(CLIENT) : $(OBJCLNTT) $(LIBFT)
	$(CC) -o client -Llibft -lft $(OBJCLNTT)

$(OBJCLNTT) : $(SRCCLNTT)
	$(CC) -c $(CFLAGS) -Ilibft $(SRCCLNTT)
	mv client.o ./srcs/client.o

$(LIBFT) :
	make -C libft

$(PRINTF) :
	make -C ft_printf

clean :
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(OBJSERVT) $(OBJCLNTT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
