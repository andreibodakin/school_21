# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klavada <klavada@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/24 15:46:38 by klavada           #+#    #+#              #
#    Updated: 2020/05/27 04:16:24 by klavada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

HEADER = libft.h

SRCO = $(SRCC:%.c=%.o)

SRCC_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

SRCO_BONUS = $(SRCC_BONUS:%.c=%.o)

FLAGS = -c -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

.PHONY: all clean fclean re bonus $(NAME)

all: $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

$(NAME): $(SRCO)
		$(AR) $(NAME) $(SRCO)
		$(RM) *.gch
		ranlib $(NAME)

bonus: $(SRCO) $(SRCO_BONUS)
		$(AR) $(NAME) $(SRCO) $(SRCO_BONUS)

clean:
		$(RM) $(SRCO) $(SRCO_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
