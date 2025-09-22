/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:40:09 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 17:40:25 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	in_redir_action(char **corr, int i)
{
	int input;

	input = open(corr[i + 1], O_RDONLY);
	if (input < 0 || (dup2(input, 0)) < 0)
	{
		dup2(g_env.out, 1);
		error_message(corr[i + 1], ERR_NO_FILE_OR_DIR, NULL);
		while (corr[i])
		{
			free(corr[i]);
			corr[i] = NULL;
			i++;
		}
		return (-1);
	}
	close(input);
	free(corr[i]);
	free(corr[i + 1]);
	corr[i] = NULL;
	corr[i + 1] = NULL;
	return (1);
}

int	out_redir_action(char **corr, int i, int mod)
{
	int output;

	output = open(corr[i + 1], O_WRONLY | mod | O_CREAT, 0777);
	if (output < 0 || dup2(output, 1) < 0)
	{
		perror("bash");
		while (corr[i])
		{
			free(corr[i]);
			corr[i] = NULL;
			i++;
		}
		return (-1);
	}
	close(output);
	free(corr[i]);
	free(corr[i + 1]);
	corr[i] = NULL;
	corr[i + 1] = NULL;
	return (1);
}
