#Flags===================================================================================
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
AFLAGS = -rcs

NAME = libft.a


#Sources===================================================================================
SRCS = ft_split.c \
		ft_getnbr.c \
		get_next_line.c \
		get_next_line_utils.c


#Objects====================================================================================
OBJS = $(SRCS:.c=.o)


#Rules=======================================================================================
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus