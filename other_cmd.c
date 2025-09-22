/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:48:12 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 10:54:48 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	edit_execve(char **values)
{
	int		i;
	int		execve_out;
	char	*tmp;
	char	*path_cmd;

	i = -1;
	execve_out = -1;
	if (!g_env.path)
		return (execve_out = execve(*values, values, g_env.envv));
	while (execve_out == -1 && g_env.path[++i])
	{
		tmp = ft_strjoin(g_env.path[i], "/");
		path_cmd = ft_strjoin(tmp, *values);
		execve_out = execve(path_cmd, values, g_env.envv);
		free(tmp);
		free(path_cmd);
	}
	return (execve_out);
}

static int	status_return(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			return (130);
		if (WTERMSIG(status) == 3)
			return (131);
	}
	return (WEXITSTATUS(status));
}

int			other_cmd(char **values)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (ft_strchr(*values, '/'))
			errno = execve(*values, values, g_env.envv);
		else
			errno = edit_execve(values);
		if ((errno == -1 && ft_strchr(*values, '/')) ||
			(!g_env.path && errno == -1))
			error_message(*values, ERR_NO_FILE_OR_DIR, *values);
		else if (errno == -1)
			error_message(*values, ERR_NO_COMMAND, *values);
		exit(errno);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &status, 0);
	}
	return (g_env.excode = status_return(status));
}
