#Flags========================================================================
CPP = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address

NAME = test

INCLUDE = ./

#Libraries=====================================================================


#Sources========================================================================
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

#Objects=========================================================================
OBJS = $(SRCS:.cpp=.o)


#Rules===========================================================================

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : 
	make clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
