/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:28:44 by klavada           #+#    #+#             */
/*   Updated: 2020/07/06 13:18:26 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len])
		len++;
	while (s2[i++])
		len++;
	if (!(result = (char *)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_list	*ft_lstadd_new(t_list **list, int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->tail = NULL;
	new->next = NULL;
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
	return (*list);
}

int		ft_delnode(t_list **list, void (*del)(char **), int fd)
{
	t_list *prev;
	t_list *curr;

	prev = *list;
	curr = *list;
	if (curr->fd == fd && curr->next == prev->next)
	{
		curr = curr->next;
		*list = curr;
		del(&prev->tail);
		free(prev);
		return (0);
	}
	while (curr)
	{
		if (curr->fd == fd)
		{
			prev->next = curr->next;
			del(&curr->tail);
			free(curr);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
