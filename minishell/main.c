/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:15:36 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/04 12:31:26 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	start_cmd(char **corr_sect)
{
	int ret;

	ret = 0;
	if (!ft_strcmp(corr_sect[0], "exit"))
		ret = cmd_exit(corr_sect + 1);
	else if (!ft_strcmp(corr_sect[0], "cd"))
		ret = cmd_cd(corr_sect + 1);
	else if (!ft_strcmp(corr_sect[0], "echo"))
		ret = cmd_echo(corr_sect + 1);
	else if (!ft_strcmp(corr_sect[0], "pwd"))
		ret = cmd_pwd();
	else if (!ft_strcmp(corr_sect[0], "export"))
		ret = cmd_export(corr_sect + 1);
	else if (!ft_strcmp(corr_sect[0], "unset"))
		ret = cmd_unset(corr_sect + 1);
	else if (!ft_strcmp(corr_sect[0], "env"))
		ret = cmd_env();
	else
		ret = other_cmd(corr_sect);
	dup2(g_env.in, 0);
	dup2(g_env.out, 1);
	values_free(corr_sect);
	return (ret);
}

void		start_section(char *section)
{
	char	**corr;
	int		i;
	int		redir;
	char	*sp_trim;

	sp_trim = ft_strtrim(section, " ");
	corr = parse_sections(sp_trim);
	i = g_env.redir;
	if (check_redir(corr, i))
		return ;
	while (corr[i])
	{
		redir = 0;
		if (!(ft_strcmp(corr[i], IN_RED)))
			redir = in_redir_action(corr, i);
		else if (!(ft_strcmp(corr[i], OUT_RED)))
			redir = out_redir_action(corr, i, O_TRUNC);
		else if (!(ft_strcmp(corr[i], DOB_OUT_RED)))
			redir = out_redir_action(corr, i, O_APPEND);
		if (redir == -1)
			return ;
		i += 2;
	}
	if (redir != -1)
		g_env.excode = corr[0] ? start_cmd(corr) : end_cmd(corr);
}

static void	shell_start(void)
{
	int		i;
	char	**sections;
	char	*sp_trim;
	char	*shield;

	i = -1;
	shield = parse_shield();
	sp_trim = ft_strtrim(shield, " ");
	free(shield);
	if (check_line(sp_trim))
		return ;
	sections = ft_split(sp_trim, ';');
	free(sp_trim);
	correction(sections, ';');
	while (sections[++i])
		start_pipes(sections[i]);
	values_free(sections);
}

static void	analyser(int process)
{
	if (!process)
	{
		ft_putendl_fd("exit", 2);
		exit(0);
	}
	else
		shell_start();
	if (process)
	{
		free(g_line);
		g_line = NULL;
	}
}

int			main(int argc, char **argv, char **envv)
{
	int	process;

	process = 1;
	if (argc < 1 && argv[0])
		return (-1);
	envv_init(envv);
	g_env.in = dup(0);
	g_env.out = dup(1);
	while (process)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		if (process)
			ft_putstr_fd("\033[31m➜➜➜ trololo ✗✗✗: \033[0m", 1);
		if ((process = ft_get_next_line(0, &g_line)) < 0)
			return (-1);
		analyser(process);
	}
	return (0);
}
