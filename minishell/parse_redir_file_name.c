/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_file_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:04:06 by klavada           #+#    #+#             */
/*   Updated: 2020/12/07 14:06:05 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

size_t	ft_dollar_cpy_rdr(t_prs_com *new, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len != 0)
	{
		while (src[i] && len > i)
		{
			new->rdr[new->ry][new->rz] = src[i];
			i++;
			new->rz++;
		}
	}
	return (ft_strlen(src));
}

int		find_pwds_rdr(char *var, t_prs_com *new)
{
	if (!(ft_strncmp(var, "PWD=", ft_strlen(var))))
	{
		if (g_env.pwd)
			ft_dollar_cpy_rdr(new, g_env.pwd, ft_strlen(g_env.pwd));
		return (1);
	}
	else if (!(ft_strncmp(var, "OLDPWD=", ft_strlen(var))))
	{
		if (g_env.oldpwd)
			ft_dollar_cpy_rdr(new, g_env.oldpwd, ft_strlen(g_env.oldpwd));
		return (1);
	}
	else if (!(ft_strncmp(var, "HOME=", ft_strlen(var))))
	{
		if (g_env.home)
			ft_dollar_cpy_rdr(new, g_env.home, ft_strlen(g_env.home));
		return (1);
	}
	return (0);
}

void	find_env_rdr(char *line, int start, int *i, t_prs_com *new)
{
	int		t;
	char	*var;

	t = 0;
	var = ft_part_strdup(line + start, (*i) - start);
	if (find_pwds_rdr(var, new))
	{
		free(var);
		return ;
	}
	while (g_env.envv[t])
	{
		if (!(ft_strncmp(var, g_env.envv[t], ft_strlen(var))))
		{
			ft_dollar_cpy_rdr(new, g_env.envv[t] + ft_strlen(var),
						ft_strlen(g_env.envv[t]) - ft_strlen(var));
			free(var);
			return ;
		}
		t++;
	}
	free(var);
	return ;
}

void	parse_dollar_file_name(char *line, int *i, t_prs_com *new)
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
			new->rz += ft_part_strlcpy(new->rdr[new->ry], err, ft_strlen(err));
			free(err);
		}
		(*i)++;
		return ;
	}
	while (line[(*i)])
	{
		if (char_cmp(line[(*i)], " $=;:~'\"\\-+!#%^*?,.@{}[]"))
			return (find_env_rdr(line, start, i, new));
		(*i)++;
	}
	return (find_env_rdr(line, start, i, new));
}
