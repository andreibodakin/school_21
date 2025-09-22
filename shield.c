/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:44:42 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/29 03:46:56 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static int	check_shield2(char *sh_line, int i, int j, int quotes)
{
	if ((quotes == 2 && g_line[i] == '\\') || (quotes == 0 && g_line[i] == '\\'
		&& g_line[i] == '$'))
		sh_line[j] = g_line[i];
	else if (quotes % 2 != 1 && g_line[i] == '\\' && g_line[i + 1] != '\'')
	{
		sh_line[j] = '\'';
		sh_line[j + 1] = g_line[i + 1];
		sh_line[j + 2] = '\'';
		return (1);
	}
	else
		sh_line[j] = g_line[i];
	return (0);
}

static int	check_shield(char *sh_line, int i, int j, int quotes)
{
	if (g_line[i] == '\\' && g_line[i + 1] == '\0')
	{
		free(sh_line);
		ft_putendl_fd("Incorrect data. Don't forget anything!", 2);
		return (-1);
	}
	else if (quotes == 0 && g_line[i] == '\\' && g_line[i + 1] == '\'')
	{
		sh_line[j] = g_line[i];
		sh_line[j + 1] = g_line[i + 1];
		return (2);
	}
	else
		return (check_shield2(sh_line, i, j, quotes));
}

static int	quotes_count(int i, int quotes)
{
	if (g_line[i] == '"' && !quotes)
		return (2);
	else if (g_line[i] == '\'' && !quotes)
		return (1);
	else if (quotes == 2 && g_line[i] == '\'')
		return (3);
	else if (quotes == 3 && g_line[i] == '\'')
		return (2);
	else if ((quotes == 2 && g_line[i] == '"') ||
		(quotes == 1 && g_line[i] == '\'') ||
		(quotes == 3 && g_line[i] == '"'))
		return (0);
	else
		return (quotes);
}

int			new_func(int i, int j, int quotes, char *shield_line)
{
	int	ret;

	ret = 0;
	while (g_line[++i])
	{
		quotes = quotes_count(i, quotes);
		if ((ret = check_shield(shield_line, i, j, quotes)) == 1)
		{
			i += 1;
			j += 3;
		}
		else if (ret == 0)
			j++;
		else if (ret == 2)
		{
			i++;
			j += 2;
		}
		else
			return (1);
	}
	return (0);
}

char		*parse_shield(void)
{
	char	*shield_line;
	int		quotes;
	int		i;
	int		j;

	i = -1;
	j = 0;
	quotes = 0;
	shield_line = (char *)ft_calloc(2048, sizeof(char));
	if (new_func(i, j, quotes, shield_line))
		return (ft_strdup(""));
	return (shield_line);
}
