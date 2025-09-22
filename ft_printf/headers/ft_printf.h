/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:56:09 by klavada           #+#    #+#             */
/*   Updated: 2020/07/23 18:19:57 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLG_EMPTY	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010
# define FLG_DOT	0b00000100
# define FLG_SPACE	0b00001000
# define FLG_HASH	0b00010000
# define FLG_PLUS	0b00100000

typedef	struct		s_params
{
	size_t			pos;
	ssize_t			count;
	unsigned char	flags;
	int				width;
	int				accur;
	char			type;
}					t_params;

int				ft_printf(const char *format, ...);
void			parse(const char *format, t_params *params, va_list args);
void			parse_flags(const char *format, t_params *params);
void			parse_width(const char *format, t_params *params, va_list args);
void			parse_accur(const char *format, t_params *params, va_list args);
void			print_char(t_params *params, va_list args);
void			print_str(t_params *params, va_list args);
void			print_uns(t_params *params, va_list args);
void			print_int(t_params *params, va_list args);
void			print_hex(t_params *params, va_list args);
void			print_ptr(t_params *params, va_list args);

int				ft_putchar(char c);
int				ft_isdigit(char c);
size_t			ft_strlen(const char *str);
int				ft_putnstr(char *str, int n);
char			*ft_strdup(const char *str);
char			*ft_itoa(int num);
char			*ft_uitoa(unsigned int num);
char			*ft_hextoa(unsigned int num, int letter);
char			*ft_hexlltoa(unsigned long long num);
char			ft_strchr(const char *s, int c);

#endif
