CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
AFLAGS = -rcs

INC = ./ft_printf.h
SRCS = ft_printf.c ft_write_addr.c ft_write_dec.c ft_write_hex.c ft_write_txt.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

.c.o :
	gcc $(CFLAGS) -c $< -o ${<:.c=.o} -I $(INC)

clean :
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re