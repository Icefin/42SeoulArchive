#Flags========================================================================
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
AFLAGS = -rcs

NAME = fdf
INC = includes/

#Libraries=====================================================================
MLX_LIB = mlx
LIB_LIB = libft

MLX = libmlx.dylib
LIBFT = libft/libft.a


#Sources========================================================================
SRCS = srcs/main.c
		srcs/controller.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(NAME)

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

$(MLX) :
	make -C mlx
	cp mlx/libmlx.dylib .

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	$(foreach lib, $(MLX_LIB), make clean -C $(lib);)
	$(foreach lib, $(LIB_LIB), make fclean -C $(lib);)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(MLX)

re : fclean all
