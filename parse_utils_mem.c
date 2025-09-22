/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:30:31 by klavada           #+#    #+#             */
/*   Updated: 2020/11/30 13:15:57 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	**locate_memory(int m)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc((m + 1) * sizeof(char *));
	i = -1;
	while (++i < m)
		tmp[i] = (char *)ft_calloc(MAX_LEN, sizeof(char));
	tmp[i] = NULL;
	if (g_env.redir == 0)
		g_env.redir = i;
	return (tmp);
}

char	**locate_memory_tmp(void)
{
	char	**tmp;
	int		max;
	int		i;

	i = -1;
	max = NUM_SEC;
	tmp = (char **)malloc(max * sizeof(char *));
	while (++i < NUM_SEC)
		tmp[i] = (char *)ft_calloc(MAX_LEN, sizeof(char));
	return (tmp);
}

void	ft_copy_mem(char **com, char **rdr, t_prs_com *new)
{
	int		i;
	int		r;

	i = new->y + 1;
	if (new->ry)
		i = new->y + new->ry;
	new->res = locate_memory(i);
	i = 0;
	while (i <= new->y)
	{
		ft_part_strlcpy(new->res[i], com[i], ft_strlen(com[i]));
		i++;
	}
	r = 0;
	--i;
	if (new->ry || new->rz)
		g_env.redir = i;
	while (r < new->ry)
	{
		ft_part_strlcpy(new->res[i], rdr[r], ft_strlen(rdr[r]));
		i++;
		r++;
	}
}

void	ft_free_mem(char **com, char **rdr, char *line)
{
	int		i;

	i = -1;
	while (++i < NUM_SEC)
	{
		free(com[i]);
		free(rdr[i]);
	}
	free(com);
	com = NULL;
	free(rdr);
	rdr = NULL;
	free(line);
	line = NULL;
}

void	init_struct(t_prs_com *new, int *i, char *line)
{
	(*i) = 0;
	new->y = 0;
	new->z = 0;
	new->ry = 0;
	new->rz = 0;
	new->quotes = 0;
	new->com = locate_memory_tmp();
	new->rdr = locate_memory_tmp();
	new->res = NULL;
	g_env.redir = 0;
	space_skip(line, i);
}
