/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:25:25 by klavada           #+#    #+#             */
/*   Updated: 2020/08/01 22:19:20 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLIB_H
# define CUBLIB_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		gnl_list
{
	int				fd;
	char			*tail;
	struct gnl_list *next;
}					g_list;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
g_list				*ft_lstadd_new(g_list **list, int fd);
int					ft_delnode(g_list **list, void (*del)(char **s), int fd);

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				*ft_calloc(size_t count, size_t size);
t_list				*ft_lstlast(t_list *lst);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_bzero(void *s, size_t n);

#endif
