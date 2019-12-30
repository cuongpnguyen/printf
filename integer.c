/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:15:39 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/23 23:08:33 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_no_prec(int zero, int width, char *integer, int i)
{
	while (zero < width)
	{
		ft_putchar_count('0');
		zero++;
	}
	while (integer[i])
	{
		ft_putchar_count(integer[i]);
		i++;
	}
}

void		zero_no_prec(char *integer, t_format *format)
{
	int		i;
	int		zero;
	int		len;

	zero = 0;
	i = 0;
	len = 0;
	if (integer[i] == '-')
		ft_putchar_count('-');
	if (integer[i] == '+')
		ft_putchar_count('+');
	if (integer[i] == '-' || integer[i] == '+')
	{
		len++;
		i++;
	}
	if (format->hash && format->prec_flag == 0)
		format->zero -= 1;
	len += ft_strlen(&integer[i]);
	print_no_prec(zero, format->width - len, integer, i);
}

char		*l_flag_dec(va_list ap, t_format **dp)
{
	long long int		ll;
	long int			l;
	char				*str;

	ll = 0;
	l = 0;
	if ((*dp)->dubs == 1 || (*dp)->specifier == 'u')
	{
		if (!(ll = (long long)va_arg(ap, long long)))
			str = "0";
		else
			str = ft_itoa_long((long long)ll);
		reverse_string(&str);
	}
	else
	{
		if (!(l = (long)va_arg(ap, long)))
			str = "0";
		else
			str = ft_itoa_long((long)l);
		reverse_string(&str);
	}
	return (str);
}

char		*h_flag_dec(va_list ap, t_format **dp)
{
	signed char			c;
	short int			s;
	char				*str;

	c = 0;
	s = 0;
	if ((*dp)->dubs == 1)
	{
		if (!(c = (int)va_arg(ap, int)))
			str = "0";
		else
			str = ft_itoa((int)c);
	}
	else
	{
		if (!(s = (int)va_arg(ap, int)))
			str = "0";
		else
			str = ft_itoa((int)s);
	}
	return (str);
}

void		handle_default(va_list ap, t_format **dp)
{
	int		number;
	char	*str;

	if ((*dp)->length == 'l' && (*dp)->specifier != 'u')
		str = l_flag_dec(ap, dp);
	else if ((*dp)->length == 'h' && (*dp)->specifier != 'u')
		str = h_flag_dec(ap, dp);
	else if ((*dp)->specifier == 'u')
		str = u_flag_dec(ap, dp);
	else
	{
		if (!(number = (int)va_arg(ap, int)))
			str = "0";
		else
		{
			str = ft_itoa((int)number);
			g_value = 1;
		}
	}
	solve_int(str, *dp);
}
