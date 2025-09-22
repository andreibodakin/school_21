# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:22:27 by zdawnsta          #+#    #+#              #
#    Updated: 2020/05/04 20:22:27 by zdawnsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		get_next_line.c ft_get_next_line.c ft_strcmp.c
SRCS_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

HEADER = libft.h
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -c
AR = ar -rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RM) *.gch
	@echo "Creating of libft.a"

$(OBJS): $(SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS) $(HEADER)

$(OBJS_B): $(SRCS_B) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS_B) $(HEADER)

bonus: $(OBJS) $(OBJS_B)
	@$(AR) $(NAME) $(OBJS) $(OBJS_B)
	@$(RM) *.gch
	@echo "Creating of libft.a with bonuses)"

clean:
	@$(RM) $(OBJS) $(OBJS_B)
	@echo "Cleaning of objects"

fclean: clean
	@$(RM) $(NAME)
	@echo "...and libft.a"

re: fclean all

so:
	gcc -c -fPIC ft_*.c
	gcc -shared -o libft.so ft_*.o
