/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:57:01 by klavada           #+#    #+#             */
/*   Updated: 2020/07/22 17:47:55 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

static	void	init_params(t_params *params)
{
	params->pos = 0;
	params->count = 0;
}

static	void	reset_params(t_params *params)
{
	params->flags = FLG_EMPTY;
	params->width = 0;
	params->accur = 0;
	params->type = '\0';
}

static	void	print_run(t_params *params, va_list args)
{
	if (params->type == 'c' || params->type == '%')
		print_char(params, args);
	else if (params->type == 's')
		print_str(params, args);
	else if (params->type == 'p')
		print_ptr(params, args);
	else if (params->type == 'd' || params->type == 'i')
		print_int(params, args);
	else if (params->type == 'u')
		print_uns(params, args);
	else if (params->type == 'x' || params->type == 'X')
		print_hex(params, args);
	else
		params->count = -1;
}

static	void	print_format(const char *format, t_params *params, va_list args)
{
	while (format[params->pos] != '\0')
	{
		if (format[params->pos] == '%')
		{
			params->pos++;
			if (format[params->pos] == '\0')
			{
				params->count = -1;
				return ;
			}
			reset_params(params);
			parse(format, params, args);
			print_run(params, args);
			if (params->count == -1)
				return ;
		}
		else
			params->count += ft_putchar(format[params->pos]);
		params->pos++;
	}
}

int				ft_printf(const char *format, ...)
{
	ssize_t		result;
	va_list		args;
	t_params	*params;

	if (!format || !(params = (t_params*)malloc(sizeof(t_params))))
		return (-1);
	init_params(params);
	va_start(args, format);
	print_format(format, params, args);
	va_end(args);
	result = params->count;
	free(params);
	return (result);
}
