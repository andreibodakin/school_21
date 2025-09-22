/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:45:05 by klavada           #+#    #+#             */
/*   Updated: 2020/11/30 12:07:48 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	space_skip(char *line, int *i)
{
	while (line[(*i)])
	{
		if (line[(*i)] == ' ')
			(*i)++;
		else
			return ;
	}
}

char	*ft_part_strdup(const char *src, int size)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '=';
	dest[i] = '\0';
	return (dest);
}

size_t	ft_part_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len != 0)
	{
		while (src[i] && len > i)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (ft_strlen(src));
}

int		char_cmp(char ch, char *stop)
{
	int	i;

	i = 0;
	while (stop[i])
	{
		if (ch == stop[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_num_or_question(int c)
{
	if ((c > 47 && c < 58) || c == 63)
		return (1);
	else
		return (0);
}
