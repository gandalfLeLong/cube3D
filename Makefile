# -------------------------Makefile-------------------------
NAME	= cub3D

DEBUG	= debug

HEADER			= includes/cub3D.h

SRCS			= main.c \

SRC			= ${addprefix sources/, ${SRCS}}

SRCS_PARSING	= check_args.c \
				  data_capture.c \
				  parse_texture.c \
				  texture_to_image.c \
				  parse_rgb.c \
				  parse_map.c \
				  check_map.c \

SRC_PARSING		= ${addprefix sources/parsing/, ${SRCS_PARSING}}

SRCS_EXEC		= game_init.c \
				  game_loop.c \
				  destroy_game.c \
				  init_utils.c \
				  mlx_utils.c \
				  key.c \
				  move.c \
				  move_2.c \

SRC_EXEC		= ${addprefix sources/exec/, ${SRCS_EXEC}}

SRCS_UTILS		= free_char.c \
				  error.c \

SRC_UTILS		=${addprefix sources/utils/, ${SRCS_UTILS}}

ALL_SRC			= ${SRC} ${SRC_PARSING} ${SRC_EXEC} ${SRC_UTILS} 

# -------------------------Objects--------------------------

OBJECTS_DIR		= object_files/

OBJS			= ${addprefix ${OBJECTS_DIR}, ${ALL_SRC:.c=.o}}

# -------------------------Compilation----------------------

CC			= cc

FLAGS			= -Wall -Wextra -Werror -O3 -flto -ffast-math -march=native

MLX_FLAGS		= -framework OpenGL -framework AppKit

RM			= rm -rf

FSANITIZE		= -fsanitize=address -g


# -------------------------Libraries----------------------

FT_FOLDER		= lib/libft

MLX_FOLDER		= lib/mlx

FT				= ${FT_FOLDER}/libft.a

MLX				= ${MLX_FOLDER}/mlx.a

MAKE_FT			= make -s -C ${FT_FOLDER}

MAKE_MLX		= make -s -C ${MLX_FOLDER}

INCLUDES		=	-I ${FT_FOLDER}/includes \
					-I ${MLX_FOLDER} \
					-I ./includes \
					-I /opt/X11/include -Imlx \

LIBRARIES		= -L./${FT_FOLDER} -lft \
				  -L./${MLX_FOLDER} -lmlx

# -------------------------Rules--------------------------

all:	${OBJECTS_DIR} ${NAME}

${NAME}:	${FT} ${OBJS} ${HEADER}
	@${CC} ${FLAGS} ${OBJS} ${LIBRARIES} -o ${NAME} ${MLX_FLAGS}
	@echo "Cub3D is ready"

${FT}:
	@${MAKE_FT}
	@${MAKE_MLX}
	@echo "Libraries compiled"

${OBJECTS_DIR}%.o: %.c
	@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@
	@echo "Object compiled"

${OBJECTS_DIR}:
	@mkdir -p ${OBJECTS_DIR}
	@mkdir -p ${OBJECTS_DIR}sources
	@mkdir -p ${OBJECTS_DIR}sources/parsing
	@mkdir -p ${OBJECTS_DIR}sources/exec
	@mkdir -p ${OBJECTS_DIR}sources/utils
	@mkdir -p ${OBJECTS_DIR}sources/error

debug:	${FT} ${OBJS} ${HEADER}
	@${CC} ${FLAGS} ${FSANITIZE} ${OBJS} ${LIBRARIES} -o ${DEBUG} ${MLX_FLAGS}
	@echo "Debug version is ready"

clean:	
	@${RM} ${OBJECTS_DIR}
	@${MAKE_FT} clean
	@${MAKE_MLX} clean

fclean:	clean
	@${RM} ${DEBUG} ${NAME} 
	@${MAKE_FT} fclean
	@${MAKE_MLX} fclean
	@echo "Repository cleaned"

re:	fclean all
