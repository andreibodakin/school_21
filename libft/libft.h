/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:17:09 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/04 20:17:09 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define FD 1024

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
char				g_buf[2];

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *src1, const void *src2, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

size_t				ft_strlcat(char *dst, const char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);

char				*ft_itoa(int n);
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *src, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *big, const char *small, size_t len);
char				*ft_strrchr(const char *src, int c);
char				*ft_strtrim(const char *s, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);

void				ft_bzero(void *dest, size_t len);
void				*ft_calloc(size_t len, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_free_null(void **el);

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);

int					get_next_line(int fd, char **line);
int					ft_get_next_line(int fd, char **line);

#endif
