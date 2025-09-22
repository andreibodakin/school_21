/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:03:52 by klavada           #+#    #+#             */
/*   Updated: 2020/08/01 22:21:02 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

static void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return ;
}

char		*check_tail(char **tail, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (*tail)
	{
		if ((ptr_n = ft_strchr(*tail, '\n')))
		{
			*ptr_n = '\0';
			ft_strcpy(*line, *tail);
			ft_strcpy(*tail, ++ptr_n);
		}
		else
		{
			ft_strcpy(*line, *tail);
			ft_free(tail);
		}
	}
	return (ptr_n);
}

int			get_line(int fd, char **line, char **tail, g_list **list)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ptr_n;
	char	*tmp_line;
	int		readed;

	ptr_n = check_tail(tail, line);
	while (!ptr_n && (readed = read(fd, buf, BUFFER_SIZE)))
	{
		buf[readed] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			*tail = ft_strjoin(++ptr_n, "");
		}
		tmp_line = *line;
		if (!(*line = ft_strjoin(*line, buf)) || readed < 0)
			return (ft_delnode(list, ft_free, fd) - 1);
		ft_free(&tmp_line);
	}
	return (readed || ptr_n) ? 1 : ft_delnode(list, ft_free, fd);
}

int			get_next_line(int fd, char **line)
{
	static g_list	*list;
	g_list			*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
			!(*line = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (!list)
		if (!(list = ft_lstadd_new(&list, fd)))
			return (-1);
	tmp = list;
	while (tmp->next && fd != tmp->fd)
		tmp = tmp->next;
	if (fd != tmp->fd)
	{
		if (!(list = ft_lstadd_new(&list, fd)))
			return (-1);
		tmp = list;
	}
	return (get_line(fd, line, &tmp->tail, &list));
}
