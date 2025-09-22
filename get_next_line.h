/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:55:12 by klavada           #+#    #+#             */
/*   Updated: 2020/07/05 13:52:39 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_list
{
	int				fd;
	char			*tail;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
t_list				*ft_lstadd_new(t_list **list, int fd);
int					ft_delnode(t_list **list, void (*del)(char **s), int fd);

#endif
