/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:17:14 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/24 11:17:20 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int		check_semicolon(char *line, int i, char quotes)
{
	int	j;

	j = skip_space(line, i);
	if (line[j] == ';' && !quotes && i == 0)
	{
		if (line[j + 1] == ';')
			error_message(";;", ERR_TOKEN, line);
		else
			error_message(";", ERR_TOKEN, line);
		return (1);
	}
	else if (line[j] == ';' && !quotes && i > 0)
	{
		if (line[j + 1] != ';' && line[i - 1] != ';')
			return (0);
		else if (line[j + 1] == ';')
			error_message(";;", ERR_TOKEN, line);
		else if (line[i - 1] == ';')
			error_message(";", ERR_TOKEN, line);
		return (1);
	}
	else if (line[i] == ';' && quotes)
		line[i] = TEMP_CHAR;
	return (0);
}

int		check_pipes2(char *line, int i, int j)
{
	if (line[j + 1] == '\0')
	{
		ft_putendl_fd("Incorrect data. Don't forget anything!", 2);
		free(line);
	}
	else if (line[j + 1] == '|' && line[j + 2] == '\0')
	{
		ft_putendl_fd("Incorrect data. Don't forget anything!", 2);
		free(line);
	}
	else if (line[i - 1] == '|' || line[skip_space(line, j + 1)] == '|')
		error_message("|", ERR_TOKEN, line);
	else if (line[j + 1] == '|')
		error_message("||", ERR_TOKEN, line);
	else if (line[j + 1] != '|' && line[i - 1] != '|')
		return (0);
	return (1);
}

int		check_pipes(char *line, int i, char quotes)
{
	int	j;

	j = skip_space(line, i);
	if (line[j] == '|' && !quotes && i == 0)
	{
		if (line[j + 1] == '|')
			error_message("||", ERR_TOKEN, line);
		else
			error_message("|", ERR_TOKEN, line);
		return (1);
	}
	else if (line[j] == '|' && !quotes && i > 0)
		return (check_pipes2(line, i, j));
	else if (line[i] == '|' && quotes)
		line[i] = TEMP_CHAR;
	return (0);
}

int		check_line(char *line)
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
		if (check_semicolon(line, i, quotes))
			return (1);
	}
	return (0);
}

int		check_redir(char **corr, int i)
{
	if (i < 0)
		return (0);
	while (corr[i])
	{
		if (!corr[i + 1])
		{
			error_message("newline", ERR_REDIR, NULL);
			values_free(corr);
			return (1);
		}
		else if (!(ft_strcmp(corr[i + 1], IN_RED)) ||
			!(ft_strcmp(corr[i + 1], OUT_RED)) ||
			!(ft_strcmp(corr[i + 1], DOB_OUT_RED)))
		{
			error_message(corr[i + 1], ERR_REDIR, NULL);
			values_free(corr);
			return (1);
		}
		else
			i += 2;
	}
	return (0);
}
