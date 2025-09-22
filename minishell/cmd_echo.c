/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:44:25 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/23 14:35:44 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	echo_execve(char **argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			write(1, " ", 1);
	}
}

int			cmd_echo(char **argv)
{
	int i;

	i = -1;
	if (count_args(argv) > 0 && !ft_strncmp(argv[0], "-n\0", 3))
		echo_execve(argv + 1);
	else
	{
		echo_execve(argv);
		write(1, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
