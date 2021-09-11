NAME = cub3D

LIBFT = ./libs/libft/libft.a

MLX = ./libs/mlx/libmlx_Linux.a

CUB_SRCS = \
		./game/main.c\
		./game/raycaster.c\
		./game/utils.c\
		./game/draw/display.c\
		./game/draw/draw.c\
		./game/init/init.c\
		./game/move/get_user_input.c\
		./game/move/move.c\
		./game/move/move2.c\
		./game/parsing/checks.c\
		./game/parsing/errors.c\
		./game/parsing/flood_fill.c\
		./game/parsing/parse_file.c\
		./game/parsing/parse_map.c\
		./game/parsing/parse_settings.c\

CC = clang

CUB_OBJS = ${CUB_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g

MAC_MLX_EXT = -framework OpenGL -framework Appkit

LINUX_MLX_EXT = -lXext -lX11 -lm

all : $(NAME)

.c.o :
		${CC} ${CFLAGS} -Ilibft -Iheaders -Iminilibx -c $< -o ${<:.c=.o} 

$(NAME): ${CUB_OBJS}
		make -C libs/libft
		make -C libs/mlx
		${CC} ${LINUX_MLX_EXT} -o ${NAME} ${CUB_OBJS} ${MLX} ${LIBFT}

clean :
		rm -rf ${CUB_OBJS}
		make clean -C ./libs/libft

fclean: clean
		make fclean -C ./libs/libft 
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
