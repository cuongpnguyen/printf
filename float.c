/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:42:37 by cnguyen           #+#    #+#             */
/*   Updated: 2019/12/01 22:08:56 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision_float(char **dp, int precision)
{
	char		*tmp;
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = *dp;
	tmp = malloc(32);
	while (str[i] != '.')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = str[i];
	i++;
	while (j < precision)
	{
		tmp[i + j] = str[i + j];
		j++;
	}
	free(str);
	*dp = tmp;
}

void		remove_dot(char **dp)
{
	char		*tmp;
	char		*str;
	int			i;

	i = 0;
	str = *dp;
	tmp = malloc(32);
	while (str[i] != '.')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	*dp = tmp;
}

void		adjust_float_precision(char **dp, t_format *format)
{
	char		*str;

	str = *dp;
	if (format->prec_flag == 1)
	{
		if (format->precision == 0)
			remove_dot(&str);
		else
			precision_float(&str, format->precision);
	}
	*dp = str;
}

char		*handle_float_ld(va_list ap, t_format **dp)
{
	char			*str;
	long	double	lf;
	int				precision;

	str = malloc(32);
	if (!(lf = (long double)va_arg(ap, long double)))
	{
		str = "0";
		str[1] = '\0';
	}
	if ((*dp)->prec_flag == 1 && (*dp)->precision >= 6)
		precision = (*dp)->precision;
	else
		precision = 6;
	construct_integral_ld(lf, &str, precision);
	adjust_float_precision(&str, *dp);
	return (str);
}

void		handle_float(va_list ap, t_format **dp)
{
	double	f;
	char	*str;
	int		precision;

	if ((*dp)->specifier == 'p')
		(*dp)->hash = 1;
	if ((*dp)->length == 'L')
		str = handle_float_ld(ap, dp);
	else
	{
		str = malloc(32);
		if (!(f = (double)va_arg(ap, double)))
		{
			str[0] = '0';
			str[1] = '\0';
		}
		if ((*dp)->prec_flag == 1 && (*dp)->precision >= 6)
			precision = (*dp)->precision;
		else
			precision = 6;
		construct_integral(f, &str, precision);
		adjust_float_precision(&str, *dp);
	}
	solve_int(str, *dp);
}
