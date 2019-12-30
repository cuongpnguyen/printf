/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:20:28 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/11 17:32:34 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_pct(t_format **dp)
{
	t_format	*format;
	char		c;

	c = '%';
	format = *dp;
	if (format->zero && format->minus == 0)
		format->pad = '0';
	if (format->width > 1)
	{
		if (format->minus)
		{
			ft_putchar_count(c);
			print_width(format->width - 1, format->pad);
		}
		else
		{
			print_width(format->width - 1, format->pad);
			ft_putchar_count(c);
		}
	}
	else
		ft_putchar_count(c);
	return ;
}

int			print_spec(char c, va_list ap, t_format **dp)
{
	(*dp)->specifier = c;
	if (c == 'c')
		print_chr(ap, dp);
	else if (c == 's')
		print_str(ap, dp);
	else if (c == 'd' || c == 'i' || c == 'D')
		print_int(ap, dp);
	else if (c == 'o')
		handle_octal(ap, dp);
	else if (c == 'x')
		handle_hex(ap, dp, 0);
	else if (c == 'X')
		handle_hex(ap, dp, 1);
	else if (c == '%')
		print_pct(dp);
	else if (c == 'u')
		print_int(ap, dp);
	else if (c == 'p')
		handle_hex(ap, dp, 0);
	else if (c == 'f')
		handle_float(ap, dp);
	return (1);
}

void		print_chr(va_list ap, t_format **dp)
{
	t_format	*format;
	char		c;

	c = va_arg(ap, int);
	format = *dp;
	if (format->width > 1)
	{
		if (format->minus)
		{
			ft_putchar_count(c);
			print_width(format->width - 1, format->pad);
		}
		else
		{
			print_width(format->width - 1, format->pad);
			ft_putchar_count(c);
		}
	}
	else
		ft_putchar_count(c);
	return ;
}

void		print_int(va_list ap, t_format **dp)
{
	if ((*dp)->length == '\0')
		handle_default(ap, dp);
	else if ((*dp)->length == 'h')
		handle_default(ap, dp);
	else if ((*dp)->length == 'h' && (*dp)->dubs == 1)
		handle_default(ap, dp);
	else
		handle_default(ap, dp);
}

void		print_str(va_list ap, t_format **dp)
{
	t_format	*format;
	char		*str;
	int			len;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	format = *dp;
	len = determine_len(str, format->prec_flag, format->precision);
	if (format->width)
	{
		if (format->minus)
		{
			precision_print(str, format->prec_flag, format->precision);
			print_width(format->width - len, format->pad);
		}
		else
		{
			print_width(format->width - len, format->pad);
			precision_print(str, format->prec_flag, format->precision);
		}
	}
	else
		precision_print(str, format->prec_flag, format->precision);
	return ;
}
