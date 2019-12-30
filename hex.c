/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:42:02 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:08 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_to_hex(unsigned long decimal, int upper)
{
	char			*hex;
	unsigned long	rem;
	int				i;
	char			ascii;

	if (upper)
		ascii = 'A';
	else
		ascii = 'a';
	hex = malloc(sizeof(char) * 36);
	i = 0;
	while (decimal)
	{
		rem = decimal % 16;
		if (rem <= 9)
			hex[i] = rem + '0';
		else
			hex[i] = (rem - 10) + ascii;
		decimal = decimal / 16;
		i++;
	}
	hex[i] = '\0';
	reverse_string(&hex);
	return (hex);
}

char		*h_flag_hex(t_format **dp, va_list ap, int c)
{
	unsigned int		unsign;
	unsigned char		uc;
	char				*str;

	unsign = 0;
	uc = 0;
	if ((*dp)->dubs == 1)
	{
		if (!(uc = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = convert_to_hex(uc, c);
	}
	else
	{
		if (!(unsign = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = convert_to_hex(unsign, c);
	}
	return (str);
}

char		*l_flag_hex(va_list ap, int c)
{
	unsigned long long		unsign;
	char					*str;

	unsign = 0;
	if (!(unsign = (unsigned long long)va_arg(ap, unsigned long long)))
		str = "0";
	else
		str = convert_to_hex(unsign, c);
	return (str);
}

void		handle_hex(va_list ap, t_format **dp, int c)
{
	t_format		*format;
	char			*str;

	if ((*dp)->specifier == 'p')
	{
		(*dp)->hash = 1;
		(*dp)->width -= 2;
	}
	if (c)
		(*dp)->hash_case = 1;
	format = *dp;
	if ((*dp)->length == 'l')
		str = l_flag_hex(ap, c);
	else if ((*dp)->specifier == 'p')
	{
		str = l_flag_hex(ap, c);
	}
	else
	{
		str = h_flag_hex(dp, ap, c);
	}
	solve_int(str, *dp);
}
