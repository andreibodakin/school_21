NAME = ft_containers

NAME_TEST = test_ft_containers

SRC_DIR = main_dir/
SRC_TEST_DIR = some_test/
HPP_DIR = includes/
OBJ_DIR = obj/

INCLUDES = -I$(HPP_DIR)

# Setting the compiler and the default linker program
CC = clang++
# main compilation options
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS += -g
# options for pre-processor (-I, -include, -D ... )
CPPFLAGS = -MMD $(INCLUDES)

SRC =	main.cpp

SRC_TEST =	list_test.cpp \
			all_test.cpp \
			map_test.cpp \
			queue_test.cpp \
			stack_test.cpp \
			vector_test.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

OBJ_TEST = $(addprefix $(OBJ_DIR), $(SRC_TEST:.cpp=.o))
# add list of dependency files
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

.PHONY: all clean fclean mkdir re

$(shell mkdir -p $(OBJ_DIR))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# include dependency files
-include $(DEP)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		/bin/rm -rf $(OBJ_DIR)

fclean: clean
		/bin/rm -f $(NAME)

mkdir: 
		$(shell mkdir -p $(OBJ_DIR))

test: $(NAME_TEST)

$(OBJ_DIR)%.o: $(SRC_TEST_DIR)%.cpp
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEP)

$(NAME_TEST): $(OBJ_TEST)
		$(CC) $(OBJ_TEST) -o $(NAME_TEST)

test_clean: clean
		/bin/rm -f $(NAME_TEST)

re: fclean mkdir all