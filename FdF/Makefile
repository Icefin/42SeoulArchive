CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = test.c
OBJS = test.o

NAME = fdf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
