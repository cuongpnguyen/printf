/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:17:47 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/14 13:21:50 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_justify(char *s, t_format **dp)
{
	t_format	*format;
	int			pos;

	format = *dp;
	pos = 0;
	while (ft_strcontains(JUSTIFY, s[pos]))
	{
		(s[pos] == '+') ? format->plus = 1 : 0;
		(s[pos] == '-') ? format->minus = 1 : 0;
		(s[pos] == '#') ? format->hash = 1 : 0;
		(s[pos] == '0') ? format->zero = 1 : 0;
		(s[pos] == ' ') ? format->space = 1 : 0;
		pos++;
	}
	return (pos);
}

int		set_width(char *s, t_format **dp)
{
	int			pos;
	t_format	*format;
	char		arr[14];

	format = *dp;
	pos = 0;
	while (s[pos] >= '0' && s[pos] <= '9')
	{
		arr[pos] = s[pos];
		pos++;
	}
	arr[pos] = '\0';
	format->width = ft_atoi((char *)arr);
	return (pos);
}

int		set_precision(char *s, t_format **dp)
{
	int			pos;
	int			i;
	char		arr[14];

	i = 0;
	pos = 0;
	if (s[pos] == '.')
	{
		(*dp)->prec_flag = 1;
		pos++;
		while (s[pos] >= '0' && s[pos] <= '9')
		{
			arr[i] = s[pos];
			i++;
			pos++;
		}
	}
	if (pos == 1)
		(*dp)->precision = 0;
	else
	{
		arr[i] = '\0';
		(*dp)->precision = ft_atoi((char *)arr);
	}
	return (pos);
}

int		set_length(char *s, t_format **dp)
{
	int		pos;

	pos = 0;
	while (ft_strcontains(LENGTHS, s[pos]))
	{
		if (s[pos] == 'l')
		{
			if ((*dp)->length == 'l')
				(*dp)->dubs = 1;
			(*dp)->length = 'l';
		}
		else if (*s == 'L')
			(*dp)->length = 'L';
		else if (*s == 'h')
		{
			if ((*dp)->length == 'h')
				(*dp)->dubs = 1;
			(*dp)->length = 'h';
		}
		pos += set_length_jz(*s, dp);
	}
	return (pos);
}

int		set_tokens(char *s, va_list ap, t_format **dp)
{
	int	pos;

	pos = 0;
	if (ft_strcontains(SPECIFIERS, s[pos]))
		print_spec(s[pos], ap, dp);
	else if (!ft_strcontains(SPECIFIERS, s[pos]))
	{
		pos += set_justify(s, dp);
		pos += set_width(&s[pos], dp);
		pos += set_precision(&s[pos], dp);
		pos += set_length(&s[pos], dp);
	}
	return (pos);
}
