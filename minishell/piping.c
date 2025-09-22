/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:07:05 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 11:07:15 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	seek_pipes(char *line)
{
	int		i;
	char	quotes;

	i = -1;
	quotes = 0;
	while (line[++i])
	{
		if ((line[i] == '"' || line[i] == '\'') && !quotes)
			quotes = line[i];
		else if ((line[i] == '"' || line[i] == '\'') && quotes == line[i])
			quotes = 0;
		if (check_pipes(line, i, quotes))
			return (1);
	}
	return (0);
}

static void	child_execve(int *pipe_fd, char *pipe_sect)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	start_section(pipe_sect);
	close(pipe_fd[1]);
	exit(0);
}

static void	parent_execve(int *pipe_fd, pid_t child)
{
	int stat;

	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	waitpid(child, &stat, 0);
}

static void	piping(char **pipe_sect, int pipes)
{
	int		i;
	int		**pipe_fd;
	pid_t	child[pipes];

	i = -1;
	pipe_fd = (int **)malloc(sizeof(int *) * pipes);
	while (pipe_sect[++i + 1])
	{
		pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		pipe(pipe_fd[i]);
		if ((child[i] = fork()) == 0)
			child_execve(pipe_fd[i], pipe_sect[i]);
		if (child[i] > 0)
			parent_execve(pipe_fd[i], child[i]);
		dup2(1, g_env.out);
		if (i > 0)
			free(pipe_fd[i - 1]);
	}
	start_section(pipe_sect[i]);
	close(pipe_fd[i - 1][0]);
	free(pipe_fd[i - 1]);
	free(pipe_fd);
	dup2(g_env.in, 0);
}

void		start_pipes(char *section)
{
	int		pipes;
	char	**pipe_sect;
	char	*sp_trim;

	sp_trim = ft_strtrim(section, " ");
	if (seek_pipes(sp_trim))
		return ;
	pipe_sect = ft_split(sp_trim, '|');
	free(sp_trim);
	correction(pipe_sect, '|');
	pipes = count_args(pipe_sect) - 1;
	if (pipes > 0)
		piping(pipe_sect, pipes);
	else
		start_section(*pipe_sect);
	values_free(pipe_sect);
}
