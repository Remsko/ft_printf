/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:39:02 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 16:47:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline int ft_wstrlen(wchar_t *arg)
{
	int len;

	len = 0;
	while (*arg)
	{
		if (*arg < 0 || (*arg >= 0xD800 && *arg < 0xE000))
			len += 0;
		else if (*arg < 0x80)
			len += 1;
		else if (*arg < 0x800)
			len += 2;
		else if (*arg < 0x10000)
			len += 3;
		else if (*arg < 0x110000)
			len += 4;
		arg++;
	}
	return (len);
}

inline short ft_wcharlen(wchar_t arg)
{
	if (arg < 0 || (arg >= 0xD800 && arg < 0xE000))
		return (-1);
	else if (arg < 0x80)
		return (1);
	else if (arg < 0x800)
		return (2);
	else if (arg < 0x10000)
		return (3);
	else if (arg < 0x110000)
		return (4);
	else
		return (-1);
}

inline void  get_unicode(wchar_t arg, char c[4], short len)
{
	if (len <= MB_CUR_MAX)
	{
		if (len == 1)
			c[0] = arg;
		else if (len == 2)
		{
			c[0] = 0xC0 + (arg >> 6 & 0x1F);
			c[1] = 0x80 + (arg & 0x3F);
		}
		else if (len == 3)
		{
			c[0] = 0xE0 + (arg >> 12 & 0xF);
			c[1] = 0x80 + (arg >> 6 & 0x3F);
			c[2] = 0x80 + (arg & 0x3F);
		}
		else if (len == 4)
		{
			c[0] = 0xF0 + (arg >> 18 & 0x7);
			c[1] = 0x80 + (arg >> 12 & 0x3F);
			c[2] = 0x80 + (arg >> 6 & 0x3F);
			c[3] = 0x80 + (arg & 0x3F);
		}
	}
}
