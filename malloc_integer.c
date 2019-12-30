/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:25:08 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/20 19:28:34 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_sign(char **dp, char *str, t_format *format)
{
	char		*precision_int;

	precision_int = *dp;
	if (format->plus && (str[0] != '-'))
		precision_int[0] = '+';
	else if (str[0] == '-')
		precision_int[0] = '-';
	if ((format->plus && (str[0] != '-')) || str[0] == '-')
		return (1);
	return (0);
}

int			adjust_for_sign(char **pi_dp, char *str, int *len)
{
	char	*precision_int;
	int		increment;

	increment = 0;
	precision_int = *pi_dp;
	if (*str == '-')
		increment++;
	if (precision_int[0] == '-' || precision_int[0] == '+')
		(*len)--;
	return (increment);
}

void		check_octal_case(int *number, t_format *format, int i, int len)
{
	*number = format->precision - len;
	if (format->hash && format->specifier == 'o' && format->precision && \
	(format->precision > format->width || format->precision < format->width))
		*number -= 1;
	if (i == 1)
		*number += 1;
}

char		*malloc_int(char *str, t_format *format)
{
	int		len;
	int		i;
	char	*precision_int;
	int		number;

	i = 0;
	len = determine_len_int(str, format);
	if ((format->plus && (str[0] != '-')) || str[0] == '-')
		len++;
	precision_int = (char *)malloc(len + 1);
	i += handle_sign(&precision_int, str, format);
	str += adjust_for_sign(&precision_int, str, &len);
	check_octal_case(&number, format, i, len);
	write_zeroes(&precision_int, &i, number);
	if (format->prec_flag == 1 && \
	format->precision == 0 && ft_strcmp(str, "0") == 0)
	{
		precision_int[i] = '\0';
		return (precision_int);
	}
	write_from_str(&precision_int, &i, str);
	precision_int[i] = '\0';
	if (precision_int[0] == '0' && precision_int[1] == '\0')
		format->hash = 0;
	return (precision_int);
}
