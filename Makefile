SRCS		=	so_long.c \
				parsing_utils.c \
				parsing.c \
				exit.c \
				window.c \
				shell_output.c \
				player_movement.c \
				event.c \
				enemy_movement.c \

OBJS		=	${SRCS:%.c=%.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

DEBUG_FLAGS	=	-g -fsanitize=address

MLXINCLUDES	=	-I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIBFT		=	-L./library/libft -lft

PRINTF		=	-L./library/printf -lftprintf

GNL			=	-L./library/get_next_line -lgnl

LIB			=	${LIBFT} ${PRINTF} ${GNL}

NAME		=	so_long

#rules    -------------------------------------------------------------    rules

all:	${NAME}

${NAME}:	${OBJS} library
	@${CC} ${CFLAGS} -o ${NAME} ${MLXINCLUDES} ${LIB} ${OBJS}
	@echo "\033[32mprogram succesfuly compiled\033[m"

library:	libft printf gnl

libft:
	@make -s -C library/libft
	@echo "\033[33mbuilding requiered library : libft\033[0m"
printf:
	@make -s -C library/printf
	@echo "\033[33mbuilding requiered library : printf\033[0m"
gnl:
	@make -s	-C library/get_next_line
	@echo "\033[33mbuilding requiered library : get_next_line\033[0m"

debug:	library
	@${CC} ${CFLAGS} ${DEBUG_FLAGS} -g -o ${NAME} ${MLXINCLUDES} ${LIB} ${SRCS}
	@echo "\033[32mcompilation finished\033[0m"

clean:
	@rm -f ${OBJS}
	@rm -rf ${NAME}.dSYM
	@echo "\033[32mobject file succesfuly removed\033[m"
	@make -s -C library/libft clean
	@make -s -C library/printf clean
	@make -s -C library/get_next_line clean

fclean:	clean
	@rm -f ${NAME}
	@echo "\033[32mexecutable succesfully removed\033[m"
	@make -s -C library/libft fclean
	@make -s -C library/printf fclean
	@make -s -C library/get_next_line fclean

re:		fclean all

.PHONY:	all clean fclean re
