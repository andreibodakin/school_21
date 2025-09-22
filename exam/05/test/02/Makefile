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

NAME =	exam_test

SRCS = 	test/main.cpp \
		Warlock.cpp \
		ASpell.cpp \
		ATarget.cpp \
		Fwoosh.cpp \
		Dummy.cpp \
		Fireball.cpp \
		Polymorph.cpp \
		BrickWall.cpp \
		SpellBook.cpp \
		TargetGenerator.cpp

# HEAD =	Zombie.hpp \
# 		ZombieHorde.hpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "\033[0;33mCleaning..."
	rm -rf $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

test:	all
		@./$(NAME) | cat -e | diff test/test_out.txt -
		@echo "\n\033[0;33m Test OK\033[0m"
		@rm -f $(NAME)
		@rm -rf $(OBJS)

end:
	@echo "\033[0;33m Cleaning SRC files \033[0m"

	@rm -rf Warlock.cpp
	@rm -rf Warlock.hpp

	@rm -rf ASpell.cpp
	@rm -rf ATarget.cpp
	@rm -rf Fwoosh.cpp
	@rm -rf Dummy.cpp

	@rm -rf ASpell.hpp
	@rm -rf ATarget.hpp
	@rm -rf Fwoosh.hpp
	@rm -rf Dummy.hpp

	@rm -rf	Fireball.cpp
	@rm -rf	Polymorph.cpp
	@rm -rf	BrickWall.cpp
	@rm -rf	SpellBook.cpp
	@rm -rf	TargetGenerator.cpp

	@rm -rf	Fireball.hpp
	@rm -rf	Polymorph.hpp
	@rm -rf	BrickWall.hpp
	@rm -rf	SpellBook.hpp
	@rm -rf	TargetGenerator.hpp

.PHONY: all clean fclean re test end
