#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

INCLUDE = ./includes/

#Libraries=====================================================================


#Sources========================================================================
SRCS = ./srcs/main_bonus.c \
		./srcs/chef_bonus_1.c \
		./srcs/chef_bonus_2.c \
		./srcs/philo_bonus_1.c \
		./srcs/philo_bonus_2.c \
		./srcs/philo_bonus_3.c \
		./srcs/utils_bonus_1.c \
		./srcs/utils_bonus_2.c


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
