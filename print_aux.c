/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:24:13 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/20 16:24:27 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_width(int width, char pad)
{
	while (width > 0)
	{
		ft_putchar_count(pad);
		width--;
	}
}

int			print_padding(int zeroes, int remaining, char pad)
{
	while (zeroes < remaining)
	{
		ft_putchar_count(pad);
		zeroes++;
	}
	return (zeroes);
}

void		ft_putchar_count(char c)
{
	ft_putchar(c);
	g_count++;
}

void		ft_putstr_count(char *str)
{
	ft_putstr(str);
	g_count += ft_strlen(str);
}
