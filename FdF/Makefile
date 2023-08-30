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
SRCS = srcs/main.c \
		srcs/error.c \
		srcs/map.c \
		srcs/object.c \
		srcs/camera.c\
		srcs/window.c \
		srcs/fdf.c \
		srcs/vector.c \
		srcs/matrix.c \
		srcs/bresenham.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

$(MLX) :
	make -C mlx
	cp mlx/libmlx.dylib .

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	make clean -C mlx
	make fclean -C libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(MLX)

re : fclean all
