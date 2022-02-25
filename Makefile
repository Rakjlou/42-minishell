# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajung <ajung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/02/25 17:39:15 by ajung            ###   ########.fr        #
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
	src/parser/command/is.c \
	src/parser/command/get.c \
	src/parser/command/simple.c \
	src/parser/command/simple_run.c \
	src/parser/command/list.c \
	src/parser/command/pipeline.c \
	src/parser/command/compound.c \
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
	src/adrian/test.c \
	src/adrian/utils1.c \
	src/adrian/shell.c \
	src/adrian/signal.c \
	src/adrian/wordexp/wordexp.c \
	src/adrian/wordexp/fieldsplit.c \
	src/adrian/wordexp/param_exp/paramexp.c \
	src/adrian/wordexp/pathname.c \
	src/adrian/wordexp/unquoting.c \
	src/adrian/wordexp/syntaxerror.c \
	src/adrian/perror_exit.c \
	src/env/content_destroy.c \
	src/env/set_value.c \
	src/env/env_free.c \
	src/env/env_init.c \
	src/env/env_print.c \
	src/env/get_value.c \
	src/env/unset.c \


OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

CC = gcc

LIBFT_DIR = libft

CFLAGS = -Wall -Wextra -Werror \
			-MMD -g3 \
			-I . \
			-I inc/ \
			-I libft/ \
			 #-pedantic -ansi

LDFLAGS = -L $(LIBFT_DIR) \

LDLIBS = -lft \
		-lreadline \

all: libft $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)$(CFLAGS)

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
	./minishell

.PHONY: clean fclean re libft test

-include $(OBJ:.o=.d)
