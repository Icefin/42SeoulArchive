#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

NAME = philo

INCLUDE = ./includes/

#Libraries=====================================================================


#Sources========================================================================
SRCS = ./srcs/main.c \
		./srcs/chef_1.c \
		./srcs/chef_2.c \
		./srcs/philo_1.c \
		./srcs/philo_2.c \
		./srcs/philo_3.c \
		./srcs/philo_4.c \
		./srcs/philo_5.c \
		./srcs/utils.c


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
