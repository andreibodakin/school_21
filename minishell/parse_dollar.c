/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:01:49 by klavada           #+#    #+#             */
/*   Updated: 2020/11/30 16:06:05 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	parse_quotes(char *line, int *i, t_prs_com *new)
{
	if (!new->quotes)
	{
		if (line[(*i)] == '\'')
			new->quotes = 1;
		else if (line[(*i)] == '"')
			new->quotes = 2;
	}
	else
	{
		if (new->quotes == 1 && line[(*i)] == '\'')
		{
			new->quotes = 0;
			if (line[(*i) - 1] == '\'' && line[(*i) + 1] == ' ')
				new->com[new->y][new->z++] = TEMP_CHAR;
		}
		else if (new->quotes == 2 && line[(*i)] == '"')
		{
			new->quotes = 0;
			if (line[(*i) - 1] == '"' && line[(*i) + 1] == ' ')
				new->com[new->y][new->z++] = TEMP_CHAR;
		}
		else
			new->com[new->y][new->z++] = line[(*i)];
	}
	(*i)++;
}

void	ft_dollar_strlcpy(t_prs_com *new, const char *src, size_t len)
{
	int		i;
	size_t	w;
	char	*param;

	param = new->com[new->y];
	i = 0;
	w = new->z;
	while (src[i] && len > (size_t)i)
	{
		if (src[i] == ' ' && !new->quotes)
		{
			space_skip((char *)src, &i);
			new->y++;
			new->z = 0;
			w = 0;
			param = new->com[new->y] + new->z;
		}
		else if (src[i] == ' ' && new->quotes == 2)
		{
			param[w++] = src[i++];
			space_skip((char *)src, &i);
		}
		param[w++] = src[i++];
	}
	new->z = w;
}

int		find_pwds(char *var, t_prs_com *new)
{
	if (!(ft_strncmp(var, "PWD=", ft_strlen(var))))
	{
		if (g_env.pwd)
			ft_dollar_strlcpy(new, g_env.pwd, ft_strlen(g_env.pwd));
		return (1);
	}
	else if (!(ft_strncmp(var, "OLDPWD=", ft_strlen(var))))
	{
		if (g_env.oldpwd)
			ft_dollar_strlcpy(new, g_env.oldpwd, ft_strlen(g_env.oldpwd));
		return (1);
	}
	else if (!(ft_strncmp(var, "HOME=", ft_strlen(var))))
	{
		if (g_env.home)
			ft_dollar_strlcpy(new, g_env.home, ft_strlen(g_env.home));
		return (1);
	}
	return (0);
}

void	find_env(char *line, int start, int *i, t_prs_com *new)
{
	int		t;
	char	*var;

	t = 0;
	var = ft_part_strdup(line + start, (*i) - start);
	if (find_pwds(var, new))
	{
		free(var);
		return ;
	}
	while (g_env.envv[t])
	{
		if (!(ft_strncmp(var, g_env.envv[t], ft_strlen(var))))
		{
			ft_dollar_strlcpy(new, g_env.envv[t] + ft_strlen(var),
						ft_strlen(g_env.envv[t]) - ft_strlen(var));
			free(var);
			return ;
		}
		t++;
	}
	free(var);
	return ;
}

void	parse_dollar(char *line, int *i, t_prs_com *new)
{
	int		start;
	char	*err;

	(*i)++;
	start = (*i);
	if (ft_is_num_or_question((int)line[(*i)]))
	{
		if ((int)line[(*i)] == 63)
		{
			err = ft_itoa(g_env.excode);
			new->z += ft_part_strlcpy(new->com[new->y], err, ft_strlen(err));
			free(err);
		}
		(*i)++;
		return ;
	}
	while (line[(*i)])
	{
		if (char_cmp(line[(*i)], " $=;:~'\"\\-+!#%^*?,.@{}[]"))
			return (find_env(line, start, i, new));
		(*i)++;
	}
	return (find_env(line, start, i, new));
}
