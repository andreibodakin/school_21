/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:39:44 by klavada           #+#    #+#             */
/*   Updated: 2020/11/30 12:06:07 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	copy_file_name_utils(char *line, int *i, t_prs_com *new)
{
	int		qw;

	qw = 0;
	while (line[(*i)])
	{
		if (!qw && line[(*i)] == '$')
			parse_dollar_file_name(line, i, new);
		if (!qw && (line[(*i)] == '"' || line[(*i)] == '\''))
		{
			qw = line[(*i)] == '\'' ? 1 : 2;
			(*i)++;
		}
		if ((qw == 1 && line[(*i)] == '\'') || (qw == 2 && line[(*i)] == '"'))
		{
			qw = 0;
			(*i)++;
		}
		if (!qw && (line[(*i)] == ' ' || line[(*i)] == '>'
				|| line[(*i)] == '<'))
			break ;
		else if (line[(*i)])
			new->rdr[new->ry][new->rz++] = line[(*i)++];
	}
}

void	ft_copy_file_name(char *line, int *i, t_prs_com *new)
{
	int		tz_start;

	tz_start = new->rz;
	space_skip(line, i);
	copy_file_name_utils(line, i, new);
	space_skip(line, i);
	if (tz_start != new->rz)
	{
		new->ry++;
		new->rz = 0;
	}
}

void	save_redirect(char *line, int *i, t_prs_com *new)
{
	if (new->rz)
	{
		new->ry++;
		new->rz = 0;
	}
	if (line[(*i)] == '>' && line[(*i) + 1] != '>')
		new->rdr[new->ry][new->rz] = '>';
	else if (line[(*i)] == '>' && line[(*i) + 1] == '>')
	{
		new->rdr[new->ry][new->rz] = '>';
		(new->rz)++;
		new->rdr[new->ry][new->rz] = '>';
		(*i)++;
	}
	else if (line[(*i)] == '<')
		new->rdr[new->ry][new->rz] = '<';
	(*i)++;
	(new->ry)++;
	(new->rz) = 0;
	if (new->z)
	{
		new->z = 0;
		new->y++;
	}
	ft_copy_file_name(line, i, new);
}
