/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:33:03 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/25 11:23:46 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_null(void **el)
{
	void	**ptr;

	ptr = el;
	free(*ptr);
	*ptr = NULL;
}

static char	*join(char **line, char *buf, int *read_size)
{
	char *tmp;
	char *c;

	tmp = *line;
	c = buf;
	if (*read_size == 0 && buf[0] != '\0')
	{
		(*read_size)++;
		c = "\0";
	}
	if ((*line = ft_strjoin(*line, c)) == NULL)
	{
		ft_free_null((void **)&tmp);
		return (NULL);
	}
	ft_free_null((void **)&tmp);
	return (*line);
}

int			ft_get_next_line(int fd, char **line)
{
	int	flag;
	int	read_size;

	flag = 1;
	if ((*line = ft_strdup("")) == NULL)
		return (-1);
	ft_bzero(g_buf, 1);
	while (flag == 1 && ((read_size = read(fd, g_buf, 1)) || g_buf[0] != '\0'))
	{
		if (g_buf[0] == '\n')
		{
			g_buf[0] = '\0';
			flag = 0;
		}
		if (join(line, g_buf, &read_size) == NULL)
			return (-1);
	}
	return (read_size);
}
