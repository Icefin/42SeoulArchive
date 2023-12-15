#Flags========================================================================
CPP = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

#INCLUDE = ./includes/

#Libraries=====================================================================


#Sources========================================================================
SRCS = megaphone.cpp


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
