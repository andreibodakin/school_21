/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:16:02 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 10:46:54 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int		in_envs(char *value)
{
	int	i;
	int	j;

	i = 0;
	while (value[i] && value[i] != '=')
		i++;
	j = -1;
	while (g_env.envv[++j])
	{
		if (!ft_strncmp(g_env.envv[j], value, i) &&
			(g_env.envv[j][i] == '=' || g_env.envv[j][i] == '\0'))
			return (j);
	}
	return (0);
}

void	shell_close(int err_num)
{
	if (g_env.home)
		values_free(&g_env.home);
	if (g_env.pwd)
		values_free(&g_env.pwd);
	if (g_env.oldpwd)
		values_free(&g_env.oldpwd);
	if (g_env.envv)
		values_free(g_env.envv);
	if (g_env.path)
		values_free(g_env.path);
	exit(err_num);
}

void	correction(char **cmnds, char c)
{
	int		i;
	int		j;

	i = -1;
	while (cmnds[++i])
	{
		j = -1;
		while (cmnds[i][++j])
		{
			if (cmnds[i][j] == TEMP_CHAR)
				cmnds[i][j] = c;
		}
	}
}

int		count_args(char **section)
{
	int	i;

	i = 0;
	while (section[i])
		i++;
	return (i);
}

void	values_free(char **values)
{
	int i;

	i = -1;
	if (values)
	{
		while (values[++i])
			free(values[i]);
		free(values);
		values = NULL;
	}
}
