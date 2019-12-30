/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:16:13 by cnguyen           #+#    #+#             */
/*   Updated: 2019/09/30 00:05:30 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char			*handle_spaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

static int			max_check(long long l)
{
	l = l / 10;
	if (l > 2147483647 || l < -2147483648)
	{
		return (1);
	}
	return (0);
}

static long long	handle_neg(int neg_flag, long long temp)
{
	if (neg_flag == 0)
		return (temp);
	temp *= (-1);
	if (max_check(temp) == 1)
		return (0);
	return (temp);
}

int					ft_atoi(char *str)
{
	long long	temp;
	long long	prev;
	int			neg_flag;

	str = handle_spaces(str);
	temp = 0;
	neg_flag = 0;
	if (*str == '-')
	{
		neg_flag = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = temp;
		temp = (temp + (*str - '0')) * 10;
		if (prev > temp)
			return (neg_flag ? 0 : -1);
		str++;
	}
	temp /= 10;
	temp = handle_neg(neg_flag, temp);
	return (temp);
}
