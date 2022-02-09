# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/02/09 01:04:16 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	src/ui/init.c \
	src/ui/next.c \
	src/ui/peek.c \
	src/ui/rewind.c \
	src/ui/skip_whitespace.c \
	src/ui/token_destroy.c \
	src/ui/token_is_eof.c \
	src/ui/tokenize.c \

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
