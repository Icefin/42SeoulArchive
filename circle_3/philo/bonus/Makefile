#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

INCLUDE = ./includes/

#Libraries=====================================================================


#Sources========================================================================
SRCS = 


#Objects=========================================================================
OBJS = $(SRCS:.c=.o)


#Rules===========================================================================

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
