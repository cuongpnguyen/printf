/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:43:00 by cnguyen           #+#    #+#             */
/*   Updated: 2019/12/01 15:43:10 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		subtract_width_hash(t_format **dp, char *str)
{
	t_format *format;

	format = *dp;
	if ((format->specifier == 'X' || format->specifier == 'x') && \
	format->width && format->hash)
		(format)->width -= 2;
	else if (format->specifier == 'o' && format->width && format->hash)
		(format)->width -= 1;
	else if (format->specifier == 'p' && ft_strcmp(str, "0") == 0)
		(format)->width -= 0;
}

void		handle_hash(t_format **dp, char *str)
{
	t_format *format;

	format = *dp;
	if (format->specifier == 'X')
		ft_putstr_count("0X");
	else if (format->specifier == 'x')
		ft_putstr_count("0x");
	else if (format->specifier == 'o')
		ft_putstr_count("0");
	else if (format->specifier == 'p')
	{
		if (ft_strcmp(str, "0") != 0)
			ft_putstr_count("0x");
		else
			ft_putstr_count("0x");
	}
}
