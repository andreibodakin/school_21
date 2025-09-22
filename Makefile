# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:39:33 by zdawnsta          #+#    #+#              #
#    Updated: 2020/11/30 14:23:07 by klavada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = 	main.c \
		envv_init.c \
		cmd_pwd.c \
		cmd_cd.c \
		cmd_echo.c \
		cmd_env.c \
		cmd_unset.c \
		cmd_exit.c \
		cmd_export.c \
		other_cmd.c \
		help_func.c \
		help_func2.c \
		piping.c \
		checking.c \
		redirect.c \
		shield.c \
		parse_command.c \
		parse_utils_mem.c \
		parse_utils_str.c \
		parse_dollar.c \
		parse_redirect.c \
		parse_redir_file_name.c

HEADER = include/minishell.h

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
RMR = rm -rf

all: $(NAME)

%.o: %.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n\033[0;33mCompiling minishell"
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	$(RMR) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re
