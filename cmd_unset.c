/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 10:37:06 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static char	**del_env_var(int i)
{
	int		j;
	int		k;
	char	**new_arr;

	j = 0;
	k = -1;
	new_arr = (char **)malloc(sizeof(char *) * g_env.size);
	while (++k < g_env.size)
	{
		if (k != i)
		{
			new_arr[j] = ft_strdup(g_env.envv[k]);
			free(g_env.envv[k]);
			j++;
		}
	}
	free(g_env.envv[i]);
	free(g_env.envv);
	new_arr[j] = NULL;
	g_env.size--;
	return (new_arr);
}

static void	check_env_arr(char *value)
{
	int	i;
	int	l_env;

	i = -1;
	l_env = ft_strlen(value);
	while (++i < g_env.size)
	{
		if (!ft_strncmp(g_env.envv[i], value, l_env) &&
			(g_env.envv[i][l_env] == '=' || g_env.envv[i][l_env] == '\0'))
			g_env.envv = del_env_var(i);
	}
}

int			cmd_unset(char **values)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (values[++i])
	{
		check_env_arr(values[i]);
		if (!ft_strncmp(values[i], "PWD\0", 4) && g_env.pwd)
			ft_free_null((void **)&g_env.pwd);
		if (!ft_strncmp(values[i], "OLDPWD\0", 7) && g_env.oldpwd)
			ft_free_null((void **)&g_env.oldpwd);
		if (!ft_strncmp(values[i], "PATH\0", 5) && g_env.path)
		{
			while (g_env.path[++j])
				free(g_env.path[j]);
			free(g_env.path);
			g_env.path = NULL;
		}
	}
	return (EXIT_SUCCESS);
}
