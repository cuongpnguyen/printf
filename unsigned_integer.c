/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:19:41 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/13 22:37:09 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_u_long(unsigned long long the_long)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(22 * sizeof(char));
	while (the_long)
	{
		arr[i] = (the_long % 10) + '0';
		the_long = the_long / 10;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char			*ft_itoa_long(long long the_long)
{
	char				*arr;
	int					i;
	unsigned long long	pos;

	i = 0;
	arr = malloc(22 * sizeof(char));
	if (the_long < 0)
	{
		arr[i] = '-';
		i++;
		pos = -1 * the_long;
	}
	else
		pos = the_long;
	while (pos)
	{
		arr[i] = (pos % 10) + '0';
		pos = pos / 10;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char			*u_l_flag_dec(va_list ap, t_format **dp)
{
	unsigned long long int		ll;
	unsigned long int			l;
	char						*str;

	ll = 0;
	l = 0;
	if ((*dp)->dubs == 1 && (*dp)->specifier == 'u')
	{
		if (!(ll = (unsigned long long)va_arg(ap, unsigned long long)))
			str = "0";
		else
			str = ft_itoa_u_long((unsigned long long)ll);
		reverse_string(&str);
	}
	else
	{
		if (!(l = (unsigned long)va_arg(ap, unsigned long)))
			str = "0";
		else
			str = ft_itoa_u_long((unsigned long)l);
		reverse_string(&str);
	}
	return (str);
}

char			*u_h_flag_dec(va_list ap, t_format **dp)
{
	unsigned char			c;
	unsigned short int		s;
	char					*str;

	c = 0;
	s = 0;
	if ((*dp)->dubs == 1)
	{
		if (!(c = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = ft_itoa((unsigned int)c);
	}
	else
	{
		if (!(s = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = ft_itoa((unsigned int)s);
	}
	return (str);
}

char			*u_flag_dec(va_list ap, t_format **dp)
{
	unsigned int		number;
	char				*str;

	if ((*dp)->space)
		(*dp)->space = 0;
	if ((*dp)->plus)
		(*dp)->plus = 0;
	str = " ";
	if ((*dp)->length == 'l' && (*dp)->specifier == 'u')
		str = u_l_flag_dec(ap, dp);
	else if ((*dp)->length == 'h' && (*dp)->specifier == 'u')
		str = u_h_flag_dec(ap, dp);
	else
	{
		if (!(number = (unsigned int)va_arg(ap, unsigned int)))
			str = "0";
		else
			str = ft_itoa_long((unsigned int)number);
		reverse_string(&str);
	}
	return (str);
}
