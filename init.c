/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:59 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/10 16:17:07 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_struct(t_format **dp)
{
	t_format *format;

	format = *dp;
	format->plus = 0;
	format->minus = 0;
	format->hash = 0;
	format->zero = 0;
	format->space = 0;
	format->width = 0;
	format->prec_flag = 0;
	format->precision = 0;
	format->hash_case = 0;
	format->length = 0;
	format->dubs = 0;
	format->specifier = 0;
	format->pad = ' ';
}

void		create_struct(t_format **dp)
{
	t_format *format;

	format = malloc(sizeof(t_format));
	*dp = format;
	format->plus = 0;
	format->minus = 0;
	format->hash = 0;
	format->zero = 0;
	format->space = 0;
	format->width = 0;
	format->prec_flag = 0;
	format->precision = 0;
	format->hash_case = 0;
	format->length = 0;
	format->dubs = 0;
	format->specifier = 0;
	format->pad = ' ';
	format->l_j = 0;
	format->l_z = 0;
}

void		free_struct(t_format **dp)
{
	free(*dp);
	free(dp);
}
