/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:47:57 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/20 20:48:07 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		width_left(t_format *format, char *integer, int len)
{
	int			i;

	format->zero = 0;
	format->pad = ' ';
	subtract_width_hash(&format, integer);
	if (format->hash)
		handle_hash(&format, integer);
	if (format->zero && format->prec_flag == 0)
		zero_no_prec(integer, format);
	else
	{
		ft_putstr_count(integer);
		if (format->width > len)
		{
			i = 0;
			while (i < format->width - len)
			{
				ft_putchar_count(format->pad);
				i++;
			}
		}
	}
}

void		width_right(t_format *format, char *integer, int len)
{
	int			i;

	subtract_width_hash(&format, integer);
	if (format->zero && format->prec_flag == 0)
	{
		if (format->hash)
			handle_hash(&format, integer);
		zero_no_prec(integer, format);
	}
	else
	{
		i = 0;
		while (i < (format->width - len))
		{
			i++;
			ft_putchar_count(format->pad);
		}
		if (format->hash)
			handle_hash(&format, integer);
		ft_putstr_count(integer);
	}
}

void		width_int(t_format *format, char *integer, int len)
{
	if (format->minus)
		width_left(format, integer, len);
	else
		width_right(format, integer, len);
}

void		no_width_int(t_format *format, char *integer, char *str)
{
	char	*tmp;

	subtract_width_hash(&format, str);
	if (format->hash)
		handle_hash(&format, integer);
	if (format->prec_flag == 1 && format->precision == 0)
		zero_no_prec(integer, format);
	else
	{
		tmp = malloc_int(str, format);
		ft_putstr_count(tmp);
		free(tmp);
	}
}

void		solve_int(char *str, t_format *format)
{
	char		*integer;
	int			len;

	integer = malloc_int(str, format);
	len = ft_strlen(integer);
	if (str[0] == '0' && (format->specifier == 'p'))
		format->hash = 1;
	if (str[0] == '0' && (format->specifier == 'x' || format->specifier == 'X'))
		format->hash = 0;
	if (format->space && format->plus == 0 && integer[0] != '-')
	{
		ft_putchar_count(' ');
		format->width--;
	}
	if (format->width)
		width_int(format, integer, len);
	else
		no_width_int(format, integer, str);
}
