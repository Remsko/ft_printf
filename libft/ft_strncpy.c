/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:03:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 14:03:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *str;

	str = dest;
	while (n && *src)
	{
		*str++ = *src++;
		--n;
	}
	while (n--)
		*str++ = '\0';
	return (dest);
}
