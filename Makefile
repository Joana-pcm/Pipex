NAME = pipex

SRC = src/pipex.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

#valgrind --leak-check=full --trace-children=yes

%.o: %.c
			@${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<

$(NAME): ${OBJS}
			@${MAKE} ${LIBFT_PATH} all
					@${CC} ${OBJS} ${LIBFT} -o ${NAME}

all:	${NAME}

clean:
			@${MAKE} ${LIBFT_PATH} clean
					@${RM} ${OBJS}

fclean: clean
			@${MAKE} ${LIBFT_PATH} fclean
					@${RM} ${NAME}
					@echo "all clean"

re: fclean all

.PHONY: all clean fclean re

