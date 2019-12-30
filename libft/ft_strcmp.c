/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 01:31:58 by cnguyen           #+#    #+#             */
/*   Updated: 2019/09/26 22:34:01 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				count;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	count = 0;
	if (*str1 == 0 && *str2 == 0)
		return (0);
	if (*str1 == 0)
		return (count -= *str2);
	if (*str2 == 0)
		return (count += *str1);
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			count += *str1 - *str2;
			break ;
		}
		str1++;
		str2++;
	}
	return (count);
}
