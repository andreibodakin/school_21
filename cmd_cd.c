/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:44:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 14:44:18 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static char	*cd_path(char *value)
{
	if (!value)
		return (ft_strdup(g_env.home));
	else if (!(ft_strncmp(value, "~/", 2)))
		return (ft_strjoin(g_env.home, value + 1));
	else if (!(ft_strncmp(value, "~\0", 2)))
		return (ft_strdup(g_env.home));
	else if (!(ft_strncmp(value, "-\0", 2)) && g_env.oldpwd)
		return (ft_strdup(g_env.oldpwd));
	else if (!(ft_strncmp(value, "-\0", 2)) && !g_env.oldpwd)
		return (NULL);
	else
		return (ft_strdup(value));
}

static void	oldpwd_action(char *buff)
{
	char	*tmp1;
	char	**tmp2;

	tmp1 = ft_strjoin("export OLDPWD=", buff);
	tmp2 = ft_split(tmp1, ' ');
	cmd_export(tmp2);
	free(tmp1);
	values_free(tmp2);
}

static int	cd_action(void)
{
	char	buff[1024];

	getcwd(buff, 1024);
	if (g_env.pwd)
		free(g_env.pwd);
	g_env.pwd = ft_strdup(buff);
	return (EXIT_SUCCESS);
}

int			cmd_cd(char **values)
{
	char	*str;
	char	buff[1024];

	getcwd(buff, 1024);
	str = cd_path(*values);
	if (!str)
	{
		ft_putendl_fd("bash: cd: OLDPWD not set", 2);
		return (1);
	}
	else if (chdir(str) < 0)
	{
		error_message(str, ERR_CD_NO_FILE_OR_DIR, NULL);
		free(str);
		return (g_env.excode);
	}
	free(str);
	if (in_envs("OLDPWD"))
		oldpwd_action(buff);
	if (g_env.oldpwd)
		free(g_env.oldpwd);
	g_env.oldpwd = ft_strdup(buff);
	return (cd_action());
}
