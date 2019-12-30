/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:25:50 by cnguyen           #+#    #+#             */
/*   Updated: 2019/12/01 15:26:17 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double		exponents(int precision)
{
	double	exp;
	int		i;

	exp = 5;
	i = 0;
	while (i <= precision)
	{
		exp = exp * 0.1;
		i++;
	}
	return (exp);
}

void		construct_decimal(double value, double integral, \
char **dp, int precision)
{
	double		dubs;
	double		remainder;
	int			i;
	int			len;
	int			tmp;

	i = 0;
	len = ft_strlen((*dp));
	dubs = (double)integral;
	remainder = value - dubs;
	if (integral <= 0)
		remainder *= -1;
	remainder += exponents(precision);
	while (i < precision)
	{
		remainder *= 10;
		tmp = ((int)remainder != 9) ? (int)(remainder + 0.01) : (int)remainder;
		if (tmp == 10)
			(*dp)[len + i] = '0';
		else
			(*dp)[len + i] = ((int)remainder) + '0';
		i++;
		remainder = remainder - (int)remainder;
	}
	(*dp)[len + i] = '\0';
}

void		construct_integral(double value, char **dp, int precision)
{
	int		integral;
	char	*str;
	char	*temp_str;
	int		len;

	str = *dp;
	integral = (int)value;
	temp_str = ft_itoa(integral);
	ft_strcpy(str, temp_str);
	free(temp_str);
	len = ft_strlen(str);
	str[len] = '.';
	len++;
	construct_decimal(value, integral, dp, precision);
}

void		construct_decimal_ld(double value, double integral, \
char **dp, int precision)
{
	long double		dubs;
	long double		remainder;
	int				i;
	int				len;
	int				tmp;

	i = 0;
	len = ft_strlen((*dp));
	dubs = (double)integral;
	remainder = value - dubs;
	if (integral <= 0)
		remainder *= -1;
	remainder += exponents(precision);
	while (i < precision)
	{
		remainder *= 10;
		tmp = ((int)remainder != 9) ? (int)(remainder + 0.01) : (int)remainder;
		(*dp)[len + i] = ((int)remainder) + '0';
		i++;
		remainder = remainder - (int)remainder;
	}
	(*dp)[len + i] = '\0';
}

void		construct_integral_ld(long double value, char **dp, int precision)
{
	int		integral;
	char	*str;
	char	*temp_str;
	int		len;

	str = *dp;
	integral = (int)value;
	temp_str = ft_itoa(integral);
	ft_strcpy(str, temp_str);
	free(temp_str);
	len = ft_strlen(str);
	str[len] = '.';
	len++;
	construct_decimal(value, integral, dp, precision);
}
