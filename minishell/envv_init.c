/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:35 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/26 11:00:14 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void		signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_line && ft_strlen(g_line))
		{
			free(g_line);
			g_line = malloc(sizeof(char));
			g_line[0] = '\0';
			g_buf[0] = '\0';
		}
		write(1, "\b\b  \b\b\n", 7);
		ft_putstr_fd("\033[31m➜➜➜ trololo ✗✗✗: \033[0m", 1);
	}
	if (sig == SIGQUIT)
		write(1, "\b\b  \b\b", 6);
}

void		envv_init(char **envv)
{
	int	i;

	i = -1;
	g_env.home = NULL;
	g_env.pwd = NULL;
	g_env.oldpwd = NULL;
	while (envv[++i])
	{
		if (!ft_strncmp(envv[i], "HOME=", 5))
			g_env.home = ft_strdup(envv[i] + 5);
		if (!ft_strncmp(envv[i], "PWD=", 4))
			g_env.pwd = ft_strdup(envv[i] + 4);
		if (!ft_strncmp(envv[i], "OLDPWD=", 7))
			envv[i] = ft_strdup("OLDPWD");
		if (!ft_strncmp(envv[i], "PATH=", 5))
			g_env.path = ft_split(envv[i] + 5, ':');
	}
	g_env.size = i;
	g_env.envv = (char **)malloc(sizeof(char *) * (g_env.size + 1));
	i = -1;
	while (++i < g_env.size)
		g_env.envv[i] = ft_strdup(envv[i]);
	g_env.envv[i] = NULL;
}
