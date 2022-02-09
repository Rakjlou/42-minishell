# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/02/09 01:33:08 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	src/lexer/source/init.c \
	src/lexer/source/next.c \
	src/lexer/source/peek.c \
	src/lexer/source/skip_whitespace.c \
	src/lexer/token/destroy.c \
	src/lexer/token/is_eof.c \
	src/lexer/token/new.c \
	src/lexer/token/tokenize.c \

OBJ = $(SRC:.c=.o)

CC = gcc

LIBFT_DIR = libft

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -MMD -g3 \
			-I . \
			-I inc/ \
			-I libft/ \

LDFLAGS = -L $(LIBFT_DIR) \

LDLIBS = -lft \
			-lreadline \

all: libft $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

libft:
	make --no-print-directory -C $(LIBFT_DIR)

clean:
	make --no-print-directory -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(DEPS)

fclean: clean
	make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test: all
	valgrind \
	--leak-check=full \
	--track-origins=yes \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--suppressions=./.readline.supp \
	./minishell

.PHONY: clean fclean re libft test

-include $(OBJ:.o=.d)