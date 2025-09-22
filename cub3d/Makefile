NAME = cub3D
MLXLIB = libmlx.a
SRCS =	./raycasting.c \
		./cublib/ft_bzero.c \
		./cublib/ft_calloc.c \
		./cublib/ft_strcpy.c \
		./cublib/ft_memset.c
#		./cublib/get_next_line.c \
		./cublib/get_next_line_utils.c \
		./cublib/ft_lstnew.c \
		./cublib/ft_lstadd_back.c \
		./cublib/ft_lstsize.c \
		./cublib/ft_lstlast.c \
		./cublib/ft_putendl_fd.c \
		./cublib/ft_putchar_fd.c
OBJ = $(SRCS: .c=.o)
CC = gcc

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(MLXLIB) -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
