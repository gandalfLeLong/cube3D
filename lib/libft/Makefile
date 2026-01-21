# -----------------------------------Makefile------------------------------------
NAME		=	libft.a

# -----------------------------------Sources-------------------------------------

HEADER		=	includes/libft.h

LIBFT_SRCS	=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_split.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_free_tab.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstsize.c \
				ft_lstnew.c \

OBJ_DIR		=	objects

LIBFT_SRC	=	${addprefix sources/libft_sources/, ${LIBFT_SRCS}}

PRINTF_SRCS	=	ft_printf.c \
				ft_printf_utils.c \

PRINTF_SRC	=	${addprefix sources/printf_sources/, ${PRINTF_SRCS}}

GNL_SRCS	=	get_next_line.c \
				get_next_line_utils.c \

GNL_SRC		=	${addprefix sources/gnl_sources/, ${GNL_SRCS}}
				
ALL_SRC		=	${LIBFT_SRC} ${PRINTF_SRC} ${GNL_SRC}

OBJS		=	${addprefix ${OBJ_DIR}/, ${ALL_SRC:.c=.o}}

# -----------------------------------Compilation------------------------------------

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror
FLAGS_ARM	=	-arch arm64 -Wall -Wextra -Werror

LIB			=	ar -rc

RM			=	rm -f

# -----------------------------------Libraries--------------------------------------

INCLUDES =	-I ./includes

# -----------------------------------Rules------------------------------------------

UNAME_M := $(shell uname -m)
ifeq ($(UNAME_M), arm64)
	FLAGS := $(FLAGS_ARM)
else
	FLAGS := $(FLAGS_X86)
endif

all:			${NAME}

${NAME}:		${OBJS} ${HEADER}
			${LIB} ${NAME} ${OBJS}

${OBJ_DIR}/%.o:	%.c
			@mkdir -p $(dir $@)
			${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re:			fclean all

${OBJ_DIR}/%.o:	%.c
			@mkdir -p $(dir $@)
			${CC} ${FLAGS} -c ${INCLUDES} $< -o $@	

clean:
			@${RM} -r ${OBJ_DIR}

fclean: 		clean
			@${RM} ${NAME}
			@echo "Libft cleaned"

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re
