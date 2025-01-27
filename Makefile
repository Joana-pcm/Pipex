NAME = pipex

SRC = src/pipex.c src/valid.c src/main.c

BONUS = bonus/src/pipex_bonus.c bonus/src/valid_bonus.c \
		bonus/src/main.c

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

#To check on child processes:
#valgrind --leak-check=full --trace-children=yes

all:	${NAME}

%.o: %.c
			@${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<

$(NAME): ${OBJS}
			@${MAKE} ${LIBFT_PATH} all
					@${CC} ${OBJS} ${LIBFT} -o ${NAME}

bonus:	${OBJS_BONUS}
			@${MAKE} ${LIBFT_PATH} all
					@${CC} ${OBJS_BONUS} ${LIBFT} -o ${NAME}_bonus


clean:
			@${MAKE} ${LIBFT_PATH} clean
					@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
			@${MAKE} ${LIBFT_PATH} fclean
					@${RM} ${NAME}
					@echo "all clean"

re: fclean all

.PHONY: all clean fclean re

