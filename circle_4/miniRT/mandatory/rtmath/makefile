#Flags========================================================================
CC = cc

CFLAGS = #-fsanitize=address #-Wall -Wextra -Werror

AR = ar
AFLAGS = -rcs

INC = ./

NAME = rtmath.a

#Libraries=====================================================================


#Sources========================================================================
SRCS = rtmath_1.c \
		rtmath_2.c \
		rtmath_3.c \
		rtmath_4.c \
		rtmath_5.c \
		rtmath_6.c \
		rtmath_7.c \
		rtmath_8.c \
		rtmath_9.c \
		rtmath_10.c \
		rtmath_11.c


#Objects=========================================================================
OBJS = $(SRCS:.c=.o)


#Rules===========================================================================
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
