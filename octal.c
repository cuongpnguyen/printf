/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:29:23 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/18 16:33:18 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_u_to_octal(unsigned long long decimal)
{
	char				*octal;
	unsigned long long	rem;
	int					i;

	octal = malloc(sizeof(char) * 36);
	i = 0;
	while (decimal)
	{
		rem = decimal % 8;
		octal[i] = rem + '0';
		decimal = decimal / 8;
		i++;
	}
	octal[i] = '\0';
	reverse_string(&octal);
	return (octal);
}

char		*convert_to_octal(long long decimal)
{
	char		*octal;
	long long	rem;
	int			i;

	octal = malloc(sizeof(char) * 36);
	i = 0;
	while (decimal)
	{
		rem = decimal % 8;
		octal[i] = rem + '0';
		decimal = decimal / 8;
		i++;
	}
	octal[i] = '\0';
	reverse_string(&octal);
	return (octal);
}

char		*handle_h_octal(va_list ap, t_format **dp)
{
	t_format			*format;
	unsigned short int	ui;
	unsigned char		uc;
	char				*str;

	format = *dp;
	if (format->dubs == 0)
	{
		ui = 0;
		if (!(ui = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = convert_to_octal(ui);
	}
	else
	{
		uc = 0;
		if (!(uc = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = convert_to_octal(uc);
	}
	return (str);
}

void		handle_octal(va_list ap, t_format **dp)
{
	t_format			*format;
	unsigned int		ll;
	unsigned long long	ul;
	char				*str;

	format = *dp;
	if (format->length == 'l')
	{
		if (!(ul = (unsigned long long)va_arg(ap, unsigned long long)))
			str = "0";
		else
			str = convert_u_to_octal(ul);
	}
	else if (format->length == 'h')
		str = handle_h_octal(ap, dp);
	else
	{
		if (!(ll = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = convert_to_octal(ll);
	}
	solve_int(str, *dp);
}
