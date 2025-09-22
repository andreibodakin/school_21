/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:58:17 by klavada           #+#    #+#             */
/*   Updated: 2020/07/22 17:43:00 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

void	parse_flags(const char *format, t_params *params)
{
	while (format[params->pos])
	{
		if (format[params->pos] == '-')
			params->flags |= FLG_MINUS;
		else if (format[params->pos] == '0')
			params->flags |= FLG_ZERO;
		else if (format[params->pos] == ' ')
			params->flags |= FLG_SPACE;
		else if (format[params->pos] == '#')
			params->flags |= FLG_HASH;
		else if (format[params->pos] == '+')
			params->flags |= FLG_PLUS;
		else
			break ;	
		params->pos++;
	}
}

void	parse_width(const char *format, t_params *params, va_list args)
{
	if (format[params->pos] == '*')
	{
		params->width = va_arg(args, int);
		if (params->width < 0)
		{
			params->width *= -1;
			params->flags |= FLG_MINUS;
		}
		params->pos++;
	}
	else
	{
		while (ft_isdigit(format[params->pos]))
			params->width = params->width * 10 + (format[params->pos++] - 48);
	}
}

void	parse_accur(const char *format, t_params *params, va_list args)
{
	if (format[params->pos] == '.')
	{
		params->flags |= FLG_DOT;
		params->pos++;
		if (format[params->pos] == '*')
		{
			params->accur = va_arg(args, int);
			if (params->accur < 0)
			{
				params->accur = 0;
				params->flags &= ~FLG_DOT;
			}
			params->pos++;
		}
		else
		{
			while (ft_isdigit(format[params->pos]))
				params->accur = params->accur * 10 +
					(format[params->pos++] - 48);
		}
	}
}

void	parse(const char *format, t_params *params, va_list args)
{
	char	*types;

	types = "cspdiuxX%";
	parse_flags(format, params);
	parse_width(format, params, args);
	parse_accur(format, params, args);
	params->type = ft_strchr(types, format[params->pos]);
	if (params->flags & FLG_MINUS && params->flags & FLG_ZERO)
		params->flags &= ~FLG_ZERO;
}
