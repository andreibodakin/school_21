/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:03:43 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/23 18:05:43 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	error_message1(char *value, int err_num)
{
	if (err_num == ERR_NOT_NUM_ARG)
	{
		errno = 255;
		ft_putstr_fd("exit\nbash: exit: ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	if (err_num == ERR_MANY_ARGS)
	{
		errno = 1;
		ft_putstr_fd("exit\nbash: exit: ", 2);
		ft_putendl_fd("too many arguments", 2);
	}
	if (err_num == ERR_NO_COMMAND)
	{
		errno = 127;
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(": command not found", 2);
	}
}

static void	error_message2(char *value, int err_num)
{
	if (err_num == ERR_CD_NO_FILE_OR_DIR)
	{
		errno = 1;
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	if (err_num == ERR_NO_FILE_OR_DIR)
	{
		errno = 127;
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	if (err_num == ERR_TOKEN)
	{
		errno = 2;
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd("'", 2);
	}
}

void		error_message(char *value, int err_num, char *line)
{
	error_message1(value, err_num);
	error_message2(value, err_num);
	if (err_num == ERR_NOT_VALID_IND)
	{
		errno = 1;
		ft_putstr_fd("bash: export: `", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd("': not a valid identifier", 2);
	}
	if (err_num == ERR_REDIR)
	{
		errno = 258;
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd("'", 2);
		dup2(g_env.in, 0);
		dup2(g_env.out, 1);
	}
	free(line);
	g_env.excode = errno;
}

static int	check_value(char *value)
{
	int	i;

	i = -1;
	while (value[++i])
		if (!ft_isdigit(value[i]))
			return (1);
	return (0);
}

int			cmd_exit(char **values)
{
	if (values[0])
	{
		if (check_value(values[0]))
		{
			error_message(values[0], ERR_NOT_NUM_ARG, NULL);
			exit(g_env.excode);
		}
		else if (values[1])
		{
			error_message(NULL, ERR_MANY_ARGS, NULL);
			return (g_env.excode);
		}
		else
			g_env.excode = (unsigned char)ft_atoi(values[0]);
	}
	if (values)
		ft_putendl_fd("exit", 2);
	exit(g_env.excode);
	return (EXIT_SUCCESS);
}
