/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:49:46 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/26 11:02:13 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	rewrite_path(char *path)
{
	int	j;

	j = -1;
	if (g_env.path)
	{
		while (g_env.path[++j])
			free(g_env.path[j]);
		free(g_env.path);
		g_env.path = NULL;
	}
	g_env.path = ft_split(path + 5, ':');
}

int		skip_space(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

void	sort_arr(char **new_arr, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = size;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
			if (ft_strcmp(new_arr[j], new_arr[j + 1]) > 0)
			{
				tmp = new_arr[j];
				new_arr[j] = new_arr[j + 1];
				new_arr[j + 1] = tmp;
			}
	}
}

int		end_cmd(char **corr)
{
	dup2(g_env.in, 0);
	dup2(g_env.out, 1);
	values_free(corr);
	return (0);
}

void	adding_env2(char **values, int i)
{
	int	j;
	int	len;

	j = -1;
	len = ft_strlen(values[i]);
	while (g_env.envv[++j])
	{
		if (!ft_strncmp(g_env.envv[j], values[i], len) &&
			(g_env.envv[j][len] == '=' || g_env.envv[j][i] == '\0'))
			return ;
	}
	g_env.envv = add_env_var(values[i]);
}
