/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:40:13 by cnguyen           #+#    #+#             */
/*   Updated: 2019/09/29 22:58:05 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cp;

	len = ft_strlen((char *)s1);
	cp = (char *)ft_memalloc(len + 1);
	if (cp == NULL)
		return (NULL);
	ft_memcpy(cp, s1, len);
	return (cp);
}
