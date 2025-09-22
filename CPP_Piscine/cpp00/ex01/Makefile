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

NAME = phonebook

SRCS = 	main.cpp \
		Contact.class.cpp

HEADER = Contact.class.hpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n\033[0;33mCompiling..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	rm -rf $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re
