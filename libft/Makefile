# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:35:21 by jpatrici          #+#    #+#              #
#    Updated: 2024/10/28 16:56:22 by jpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Werror -Wall -Wextra

INCS = incs/gnl/get_next_line_bonus.c incs/gnl/get_next_line_utils_bonus.c \
	  incs/printf/ft_printf.c incs/printf/ft_printnum.c incs/printf/ft_printstr.c \
	  incs/printf/ft_printchr.c incs/printf/ft_printptr.c incs/printf/ft_printhex.c \
	  incs/printf/ft_printunint.c


SRC = ft_isprint.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isascii.c \
	  ft_isdigit.c ft_tolower.c ft_toupper.c ft_atoi.c ft_bzero.c \
	  ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
	  ft_strrchr.c ft_strtrim.c ft_substr.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c $(INCS)

OBJS = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

BONUS_OBJS = $(BONUS_SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $<

clean: 
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
