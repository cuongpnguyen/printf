/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:12:36 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/23 21:44:40 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_length_jz(char c, t_format **dp)
{
	if (c == 'j')
		(*dp)->l_j = 'j';
	if (c == 'z')
		(*dp)->l_z = 'z';
	return (1);
}

int		parse_flag(char *s, va_list ap, t_format **dp, int pos)
{
	if (!ft_strcontains(SYMBOLS, s[pos]))
		return (pos);
	while (ft_strcontains(SYMBOLS, s[pos]))
	{
		if (ft_strcontains(SPECIFIERS, s[pos]))
		{
			pos += print_spec(s[pos], ap, dp);
			reset_struct(dp);
			break ;
		}
		else
		{
			pos += set_tokens(&s[pos], ap, dp);
			continue;
		}
		pos++;
	}
	return (pos);
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_format	**dp;

	dp = malloc(sizeof(t_format *));
	create_struct(dp);
	va_start(ap, str);
	g_count = 0;
	g_value = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str += parse_flag(str, ap, dp, 0);
		}
		else
		{
			ft_putchar_count(*str);
			str++;
		}
	}
	return (g_count);
	free_struct(dp);
}
