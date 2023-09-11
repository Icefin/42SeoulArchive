#Flags========================================================================
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = fdf
INC = includes/

BONUS_FLAG = FALSE;

#Libraries=====================================================================
MLX = libmlx.dylib
LIBFT = libft/libft.a

LIB = $(MLX) $(LIBFT)

#Sources========================================================================
SRCS = srcs/main.c \
		srcs/object.c \
		srcs/camera_1.c\
		srcs/camera_2.c \
		srcs/vshader_1.c \
		srcs/vshader_2.c \
		srcs/window.c \
		srcs/fdf.c \
		srcs/vector.c \
		srcs/matrix.c \
		srcs/bresenham.c




#Objects=========================================================================
ifeq ($(BONUS_FLAG),TRUE)
	OBJS = $(SRCS:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif



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

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
