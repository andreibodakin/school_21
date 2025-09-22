
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
HEADER = headers/
LIBFT_DIR = libft/

SRCS = 	./ft_printf.c \
		./parse.c \
		./printers/print_char.c \
		./printers/print_str.c \
		./printers/print_uns.c \
	    ./printers/print_int.c \
		./printers/print_hex.c \
		./printers/print_ptr.c

OBJS = $(SRCS:.c=.o)
OBJ_DIR = ./
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a ./$(NAME)
	ar urcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)ft_printf.h
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re test
