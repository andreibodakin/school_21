/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:59:50 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 20:59:54 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

// static	void	int_helper_print(char *str, int num, t_params *params)
// {
// 	int		accur;

// 	if (num < 0 && params->point == true)
// 		params->count += ft_putchar('-');
// 	if (params->point == true)
// 	{
// 		accur = params->accur;
// 		while (accur > (int)ft_strlen(str))
// 		{
// 			params->count += ft_putchar('0');
// 			accur--;
// 		}
// 	}
// 	params->count += ft_putnstr(str, ft_strlen(str));
// }

// static	void	int_helper(char *str, int num, t_params *params)
// {
// 	if (params->m_flag == true)
// 		int_helper_print(str, num, params);
// 	if ((size_t)params->accur < ft_strlen(str))
// 		params->accur = ft_strlen(str);
// 	while (params->width > params->accur)
// 	{
// 		params->count += ft_putchar((params->z_flag == true &&
// 										params->point == false) ? '0' : ' ');
// 		params->width--;
// 	}
// 	if (params->m_flag == false)
// 		int_helper_print(str, num, params);
// }

void			print_int(t_params *params, va_list args)
{
	if (params && args)
		return ;
	return ;
// 	char	*num_str;
// 	int		num;
// 	int		old_num;

// 	num = va_arg(args, int);
// 	old_num = num;
// 	if (!num && params->point == true && !params->accur)
// 	{
// 		while (params->width--)
// 			params->count += ft_putchar(' ');
// 		return ;
// 	}
// 	if (num < 0 && (params->point == true || params->z_flag == true))
// 	{
// 		if (params->z_flag == true && params->point == false)
// 			params->count += ft_putchar('-');
// 		num *= -1;
// 		params->width--;
// 	}
// 	num_str = ft_itoa(num);
// 	int_helper(num_str, old_num, params);
// 	free(num_str);
}
