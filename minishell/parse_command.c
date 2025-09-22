/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:56:56 by klavada           #+#    #+#             */
/*   Updated: 2020/11/30 11:00:58 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	parse_letter(char *line, int *i, t_prs_com *new)
{
	int		next;

	next = (*i) + 1;
	if (line[(*i)] == '\\' && line[next] == '\'' && !new->quotes)
		(*i)++;
	else if (line[(*i)] == '\\' && line[next] == '\\' && new->quotes == 2)
		(*i)++;
	else if (line[(*i)] == '\\' && line[next] == '$' && new->quotes != 1)
		(*i)++;
	new->com[new->y][new->z] = line[(*i)];
	new->z++;
	(*i)++;
}

void	parse_tilda(int *i, t_prs_com *new)
{
	if (g_env.home)
		ft_dollar_strlcpy(new, g_env.home, ft_strlen(g_env.home));
	(*i)++;
}

void	parse_space(char *line, int *i, int *y, int *z)
{
	if ((*z))
	{
		(*y)++;
		(*z) = 0;
	}
	space_skip(line, i);
	return ;
}

char	**parse_sections(char *line)
{
	int			i;
	t_prs_com	new;

	init_struct(&new, &i, line);
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
			parse_quotes(line, &i, &new);
		else if ((line[i] == '>' || line[i] == '<') && !new.quotes)
			save_redirect(line, &i, &new);
		else if (line[i] == '$' && new.quotes != 1)
			parse_dollar(line, &i, &new);
		else if (line[i] == ' ' && !new.quotes)
			parse_space(line, &i, &new.y, &new.z);
		else if (line[i] == '~' && (line[i + 1] == ' ' ||
				line[i + 1] == '\0') && !new.quotes)
			parse_tilda(&i, &new);
		else if (line[i])
			parse_letter(line, &i, &new);
	}
	if (new.z && new.ry)
		new.y++;
	ft_copy_mem(new.com, new.rdr, &new);
	ft_free_mem(new.com, new.rdr, line);
	return (new.res);
}
