# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klavada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:39:33 by klavada           #+#    #+#              #
#    Updated: 2020/11/30 14:23:07 by klavada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	array

SRCS = 	main.cpp

HEAD = Array.hpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n\033[0;36mCompiling:" $(NAME)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0m"

clean:
	@echo "\033[0;33mCleaning..."
	rm -rf $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re
