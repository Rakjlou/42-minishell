# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/02/22 14:50:02 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	src/parser/errors.c \
	src/parser/execute.c \
	src/parser/init_destroy.c \
	src/parser/tree/dispatch.c \
	src/parser/tree/build.c \
	src/parser/tree/destroy.c \
	src/parser/tree/print.c \
	src/parser/command/build.c \
	src/parser/command/is.c \
	src/parser/command/get.c \
	src/parser/command/compound/build.c \
	src/parser/command/compound/debug.c \
	src/parser/command/compound/run.c \
	src/parser/command/list/build.c \
	src/parser/command/list/debug.c \
	src/parser/command/list/run.c \
	src/parser/command/pipeline/build.c \
	src/parser/command/pipeline/debug.c \
	src/parser/command/pipeline/run.c \
	src/parser/command/redirection/build.c \
	src/parser/command/simple/debug.c \
	src/parser/command/simple/run.c \
	src/lexer/init_destroy.c \
	src/lexer/build_token_list.c \
	src/lexer/errors.c \
	src/lexer/source/getc.c \
	src/lexer/source/incr.c \
	src/lexer/source/init.c \
	src/lexer/source/next.c \
	src/lexer/source/skip_whitespace.c \
	src/lexer/token/destroy.c \
	src/lexer/token/is.c \
	src/lexer/token/new.c \
	src/lexer/token/recognizer.c \
	src/lexer/token/candidate/incr.c \
	src/lexer/token/candidate/init.c \
	src/lexer/token/candidate/name.c \
	src/lexer/token/candidate/operator.c \
	src/lexer/token/candidate/quote.c \
	src/lexer/token/candidate/text.c \

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

CC = gcc

LIBFT_DIR = libft

CFLAGS = -Wall -Wextra -Werror \
			-MMD -g3 \
			-MMD -g3 \
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
