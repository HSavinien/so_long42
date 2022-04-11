SRCS		=	so_long.c \
				parsing_utils.c \
				parsing.c \
				error.c \
				failsafe_fct.c \

DEBUG_SRCS	=	debug.c \

OBJS		=	${SRCS:%.c=%.o}

DEBUG_OBJS	=	${DEBUG_SRCS:%.c=%.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

MLXINCLUDES	=	-I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIBFT		=	-L./library/libft -lft

PRINTF		=	-L./library/printf -lftprintf

GNL			=	-L./library/get_next_line -lgnl

LIB			=	${LIBFT} ${PRINTF} ${GNL}

NAME		=	so_long

#rules    -------------------------------------------------------------    rules

all:	debug #===================================================================/!\

${NAME}:	${OBJS} library
	@${CC} ${CFLAGS} -o ${NAME} ${MLXINCLUDES} ${LIB} ${OBJS}
	@echo "\033[32mprogram succesfuly compiled\033[m"

library:	libft printf gnl

libft:
	@make -s -C library/libft
	@echo "\033[33mbuilding requiered library : libft\033[0m"
	@make -s -C library/libft clean
printf:
	@make -s -C library/printf
	@echo "\033[33mbuilding requiered library : printf\033[0m"
	@make -s -C library/printf clean
gnl:
	@make -s	-C library/get_next_line
	@echo "\033[33mbuilding requiered library : get_next_line\033[0m"
	@make -s	-C library/get_next_line clean

debug:	library
	@${CC} ${CFLAGS} -g -o ${NAME} -fsanitize=address ${MLXINCLUDES} ${LIB} ${SRCS} ${DEBUG_SRCS}
	@echo "\033[32mcompilation finished\033[0m"

clean:
	@rm -f ${OBJS}
	@echo "\033[32mobject file succesfuly removed\033[m"
	@make -s -C library/libft clean
	@make -s -C library/printf clean
	@make -s -C library/get_next_line clean

fclean:	clean
	@rm -rf ${NAME} a.out *.dSYM
	@echo "\033[32mexecutable succesfully removed\033[m"
	@make -s -C library/libft fclean
	@make -s -C library/printf fclean
	@make -s -C library/get_next_line fclean

re:		fclean all

.PHONY:	all clean fclean re
