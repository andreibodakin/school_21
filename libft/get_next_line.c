/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:21:00 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/06/08 16:58:27 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *line, char *buff)
{
	size_t	line_len;
	size_t	buff_len;
	char	*tmp;
	char	*new_line;

	line_len = ft_strlen(line);
	buff_len = ft_strlen(buff);
	if (!(tmp = (char *)malloc(sizeof(char) * (line_len + buff_len + 1))))
		return (NULL);
	new_line = tmp;
	if (line)
	{
		while (*line)
			*tmp++ = *line++;
		free(line - line_len);
	}
	if (buff)
		while (*buff)
			*tmp++ = *buff++;
	*tmp = '\0';
	return (new_line);
}

static int	get_line(char **line, char **lines, char *new_line)
{
	char	*tmp;

	*new_line++ = '\0';
	*line = ft_strdup(*lines);
	if (*new_line == '\0')
	{
		free(*lines);
		*lines = NULL;
		return (1);
	}
	tmp = ft_strdup(new_line);
	free(*lines);
	*lines = tmp;
	return (1);
}

static int	check_rem(char **line, char **lines)
{
	char	*new_line;

	if (*lines)
	{
		if ((new_line = ft_strchr(*lines, '\n')))
			return (get_line(line, lines, new_line));
		*line = *lines;
		*lines = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*lines[1];
	char		*new_line;
	int			read_bytes;

	if (!line || fd < 0 || fd >= FD || read(fd, g_buf, 0) < 0)
		return (-1);
	ft_bzero(g_buf, 1);
	while ((read_bytes = read(fd, g_buf, 1)) > 0 || g_buf[0] != '\0')
	{
		g_buf[read_bytes] = '\0';
		if (lines[0])
			lines[0] = join_str(lines[0], g_buf);
		else
			lines[0] = ft_strdup(g_buf);
		if ((new_line = ft_strchr(lines[0], '\n')))
			return (get_line(line, &lines[0], new_line));
	}
	if (read_bytes < 0)
		return (-1);
	return (check_rem(line, &lines[0]));
}
