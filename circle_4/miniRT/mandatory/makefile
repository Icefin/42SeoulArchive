#Flags========================================================================
CC = cc

CFLAGS = #-g3 -fsanitize=address #-Wall -Wextra -Werror

NAME = minirt
INC = -Iincludes $(addprefix -I, $(wildcard includes/*))

BONUS_FLAG = FALSE

#Libraries=====================================================================
MLX 	=	libmlx.dylib
RTMATH	=	rtmath.a

LIB = $(MLX) $(RTMATH)

#Sources========================================================================
DIR_SRCS		=	./srcs
SRCS 			=	\
					main.c \

DIR_SRCS_SCENES	=	./srcs/scenes
SRCS_SCENES		=	\
					camera_1.c \
					camera_2.c \
					light_1.c \
					object_1.c \
					ray_1.c \
					scene_1.c \

DIR_SRCS_SYSTEM	=	./srcs/system
SRCS_SYSTEM		=	\
					geometry_1.c \
					geometry_2.c \
					geometry_3.c \
					geometry_4.c \
					minirt_1.c \
					minirt_2.c \
					parser_1.c \
					parser_2.c \
					parser_3.c \
					render_1.c \
					render_2.c \

DIR_SRCS_UTILS	=	./srcs/utils
SRCS_UTILS		=	\
					utils_1.c \
					utils_2.c \
					utils_3.c \
					utils_4.c \
					utils_5.c \
					utils_6.c \
					vector_1.c \
					vector_2.c \


#Objects=========================================================================
DIR_OBJS		=	./objs
DIR_OBJS_SCENES	:=	$(addprefix $(DIR_OBJS), /scenes)
DIR_OBJS_SYSTEM	:=	$(addprefix $(DIR_OBJS), /system)
DIR_OBJS_UTILS	:=	$(addprefix $(DIR_OBJS), /utils)

ifeq ($(BONUS_FLAG),TRUE)
	OBJS = $(SRCS:.c=.o)
else
	OBJS		=	$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
	OBJS_SCENES	=	$(addprefix $(DIR_OBJS_SCENES)/, $(SRCS_SCENES:.c=.o))
	OBJS_SYSTEM	=	$(addprefix $(DIR_OBJS_SYSTEM)/, $(SRCS_SYSTEM:.c=.o))
	OBJS_UTILS	=	$(addprefix $(DIR_OBJS_UTILS)/, $(SRCS_UTILS:.c=.o))
	OBJS_ALL	:=	\
					$(OBJS) \
					$(OBJS_SCENES) \
					$(OBJS_SYSTEM) \
					$(OBJS_UTILS) \

endif



#Rules===========================================================================
all : $(NAME)

$(NAME) : $(LIB) $(HEADERS) $(OBJS_ALL)
	$(CC) $(CFLAGS) $(OBJS_ALL) $(RTMATH) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX) :
	make -C mlx
	cp mlx/libmlx.dylib .

$(RTMATH) :
	$(MAKE) -C rtmath
	cp rtmath/rtmath.a .

$(LIBFT) :
	make -C libft

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS_SCENES)/%.o : $(DIR_SRCS_SCENES)/%.c | $(DIR_OBJS_SCENES)
	mkdir -p $(DIR_OBJS_SCENES)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS_SYSTEM)/%.o : $(DIR_SRCS_SYSTEM)/%.c | $(DIR_OBJS_SYSTEM)
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS_UTILS)/%.o : $(DIR_SRCS_UTILS)/%.c | $(DIR_OBJS_UTILS)
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS)	:
	mkdir -p $@
	mkdir -p $(DIR_OBJS_SCENES)
	mkdir -p $(DIR_OBJS_SYSTEM)
	mkdir -p $(DIR_OBJS_UTILS)

clean :
	$(MAKE) clean -C mlx
	$(MAKE) clean -C rtmath
	rm -rf $(DIR_OBJS)

fclean : clean
	$(MAKE) fclean -C rtmath
	rm -rf $(NAME) $(LIB)

re : 
	$(MAKE) fclean
	$(MAKE) all

bonus :
	make BONUS_FLAG=TRUE

.PHONY : all clean fclean re bonus
