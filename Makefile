NAME = libasm.a

SRC_ASM =	ft_strlen.s \
			ft_write.s \
			ft_read.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s
	
OBJ_ASM = $(SRC_ASM:.s=.o)

%.o: %.s
	nasm -f macho64 $< -o $@

$(NAME): $(OBJ_ASM)
	ar rcs $(NAME) $(OBJ_ASM)

all:
	$(MAKE) $(NAME)

test: main.c
	$(MAKE) all
	clang main.c $(NAME) -o test

clean:
	rm -f $(OBJ_ASM)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	rm -f test

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re