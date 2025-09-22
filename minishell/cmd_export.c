/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:14:56 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 10:27:58 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char		**add_env_var(char *value)
{
	int		i;
	char	**new_arr;

	i = -1;
	new_arr = (char **)malloc(sizeof(char *) * (g_env.size + 2));
	while (++i < g_env.size)
	{
		new_arr[i] = ft_strdup(g_env.envv[i]);
		free(g_env.envv[i]);
	}
	free(g_env.envv);
	new_arr[i++] = ft_strdup(value);
	new_arr[i] = NULL;
	g_env.size++;
	return (new_arr);
}

static void	adding_env(char **values, int i)
{
	int	j;

	if ((j = in_envs(values[i])))
	{
		free(g_env.envv[j]);
		g_env.envv[j] = ft_strdup(values[i]);
	}
	else
		g_env.envv = add_env_var(values[i]);
	if (!ft_strncmp(values[i], "PATH=", 5))
		rewrite_path(values[i]);
	if (!ft_strncmp(values[i], "PWD=", 4))
	{
		free(g_env.pwd);
		g_env.pwd = ft_strdup(values[i] + 4);
	}
	if (!ft_strncmp(values[i], "OLDPWD=", 7))
	{
		free(g_env.oldpwd);
		g_env.oldpwd = ft_strdup(values[i] + 7);
	}
}

static int	add_to_envs(char **values)
{
	int	i;
	int ret;

	i = -1;
	ret = 0;
	while (values[++i])
	{
		if (values[i][0] == '=' || ft_isdigit(values[i][0]))
		{
			error_message(values[i], ERR_NOT_VALID_IND, NULL);
			ret = 1;
		}
		else if (ft_strchr(values[i], '='))
			adding_env(values, i);
		else
			adding_env2(values, i);
	}
	return (ret);
}

static void	print_sort_declares(char **new_arr, int size)
{
	int	i;
	int	j;
	int	n;

	sort_arr(new_arr, size);
	i = -1;
	while (new_arr[++i])
	{
		n = 0;
		j = -1;
		ft_putstr_fd("declare -x ", 1);
		while (new_arr[i][++j])
		{
			write(1, &new_arr[i][j], 1);
			if (new_arr[i][j] == '=' && n == 0)
				n += write(1, "\"", 1);
		}
		if (n != 0)
			ft_putendl_fd("\"", 1);
		else
			ft_putendl_fd("", 1);
	}
	if (new_arr)
		values_free(new_arr);
}

int			cmd_export(char **values)
{
	char	**new_arr;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	new_arr = NULL;
	if (*values)
		ret = add_to_envs(values);
	else
	{
		new_arr = (char **)malloc(sizeof(char *) * (g_env.size + 1));
		while (g_env.envv[++i])
			new_arr[i] = ft_strdup(g_env.envv[i]);
		new_arr[i] = NULL;
		print_sort_declares(new_arr, g_env.size);
	}
	return (ret);
}
