/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:53:23 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/14 22:12:27 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digs(int nbr)
{
	int	count;

	count = 0;
	while (nbr)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

static void		fill_in(char *s, unsigned int n, int size)
{
	char			*temp;
	int				i;
	unsigned int	n_temp;

	n_temp = n;
	temp = ft_memalloc((size_t)size + 1);
	temp[size] = '\0';
	i = 0;
	while (n_temp)
	{
		temp[i] = (n_temp % 10) + '0';
		n_temp = n_temp / 10;
		i++;
	}
	size = i - 1;
	i = 0;
	while (size >= 0)
	{
		s[i] = temp[size];
		i++;
		size--;
	}
}

static char		*zero_string(void)
{
	char	*s;

	s = (char *)ft_memalloc(2);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	int				len;

	if (n == 0)
		return (zero_string());
	nbr = (unsigned int)n;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	len = count_digs(nbr);
	if (n < 0)
		len += 1;
	if (!(str = (char *)ft_memalloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		fill_in(&str[1], nbr, len);
	}
	else
		fill_in(str, nbr, len);
	return (str);
}
