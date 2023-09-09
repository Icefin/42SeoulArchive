#Flags========================================================================
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
AFLAGS = -rcs

NAME = fdf
INC = includes/

#Libraries=====================================================================
MLX = libmlx.dylib
LIBFT = libft/libft.a

LIB = $(MLX) $(LIBFT)

#Sources========================================================================
SRCS = srcs/main.c \
		srcs/object.c \
		srcs/camera.c\
		srcs/vshader.c \
		srcs/window.c \
		srcs/fdf.c \
		srcs/vector.c \
		srcs/matrix.c \
		srcs/bresenham.c




#Objects=========================================================================
OBJS = $(SRCS:.c=.o)




#Rules===========================================================================
all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
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
