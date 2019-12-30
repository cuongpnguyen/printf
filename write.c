/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:38:57 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/20 19:39:04 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_zeroes(char **dp, int *i, int number)
{
	char *precision_int;

	precision_int = *dp;
	while (*i < number)
	{
		precision_int[*i] = '0';
		(*i)++;
	}
	return ;
}

void		write_from_str(char **dp, int *i, char *str)
{
	char	*precision_int;

	precision_int = *dp;
	while (*str)
	{
		precision_int[*i] = *str;
		str++;
		(*i)++;
	}
}
