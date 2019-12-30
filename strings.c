/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:40:35 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/11 23:46:22 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			precision_print(char *str, int prec_flag, int precision)
{
	if (prec_flag == 1)
	{
		while (*str != '\0' && precision > 0)
		{
			ft_putchar_count(*str);
			str++;
			precision--;
		}
	}
	else
	{
		while (*str != '\0')
		{
			ft_putchar_count(*str);
			str++;
		}
	}
}

int				determine_len(char *str, int prec_flag, int precision)
{
	int		len;

	len = 0;
	if (prec_flag)
	{
		while (str[len] != '\0' && precision)
		{
			precision--;
			len++;
		}
		return (len);
	}
	return (ft_strlen(str));
}

int				determine_len_int(char *str, t_format *format)
{
	int		len;
	int		precision;

	precision = format->precision;
	len = 0;
	if (str[0] == '-')
		str++;
	if (format->prec_flag && precision > 0)
	{
		while (str[len] != '\0' && precision)
		{
			precision -= 1;
			len++;
		}
		return (len);
	}
	len = ft_strlen(str);
	return (len);
}

int				negative_flag(int neg)
{
	if (neg == 1)
		return (1);
	return (0);
}

void			reverse_string(char **dp)
{
	char	*s;
	int		len;
	char	temp;
	int		i;
	int		neg;

	s = *dp;
	temp = ' ';
	i = 0;
	neg = 0;
	len = ft_strlen(s);
	if (s[i] == '-')
	{
		neg = 1;
		s++;
		len--;
	}
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - 1 - i] = temp;
		i++;
	}
	s -= negative_flag(neg);
}
