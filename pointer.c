/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:32:30 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/23 17:32:47 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_to_pointer(long long decimal)
{
	char		*ptr;
	long long	rem;
	int			i;

	ptr = malloc(sizeof(char) * 36);
	i = 0;
	while (decimal)
	{
		rem = decimal % 16;
		if (rem >= 0 && rem <= 9)
			ptr[i] = rem + '0';
		else
			ptr[i] = (rem - 10);
		decimal = decimal / 16;
		i++;
	}
	ptr[i] = '\0';
	reverse_string(&ptr);
	return (ptr);
}

void		handle_pointer(va_list ap, t_format **dp)
{
	t_format		*format;
	long	long	ll;
	char			*str;

	if ((*dp)->specifier == 'p')
		(*dp)->hash = 1;
	format = *dp;
	if (!(ll = (long long)va_arg(ap, long long)))
		str = "0";
	else
		str = convert_to_pointer(ll);
	solve_ptr(str, *dp);
}

void		solve_ptr(char *str, t_format *format)
{
	char	*integer;
	int		len;

	integer = malloc_int(str, format);
	len = ft_strlen(integer);
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
	free(integer);
}
