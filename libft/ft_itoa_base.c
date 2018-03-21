/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:29:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 11:24:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CONV (value % base < 10 ? '0' : 'A' - 10)

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;
	int		tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = (value <= 0);
	tmp = value;
	while (++len && tmp)
		tmp /= base;
	if (!(str = (char *)malloc(sizeof(*str) * (len))))
		return (NULL);
	str[--len] = '\0';
	tmp = (value < 0) ? -1 : 1;
	while (len)
	{
		str[--len] = (value % base) * tmp + CONV;
		value /= base;
	}
	tmp < 0 ? *str = '-' : 0;
	return (str);
}
