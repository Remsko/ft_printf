/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:44:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/17 15:04:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

/*
 ** less than 8 bits -> 0xxxxxxx -> 0x0
 **                     mask = 01111111 -> 0x7F;
 **
 ** less than 12 bits -> 110xxxxx -> 0xC0
 **					    mask = 00011111 -> 0x1F;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 **
 ** less than 17 bits -> 1110xxxx -> 0xE0
 **					    mask = 00001111 -> 0xF;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 **
 ** less than 22 bits -> 11110xxx -> 0xF0
 **					    mask = 00000111 -> 0x7;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 **						10xxxxxx -> 0x80
 **					    mask = 00111111 -> 0x3F;
 */

inline static short	ft_wcharlen(wchar_t arg)
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

inline static void	get_unicode(wchar_t arg, char c[4], short len)
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

inline void			conv_wchar(t_env *e, wchar_t arg)
{
	char	*c;
	short	len;

	c = (char[4]){0, 0, 0, 0};
	if ((len = ft_wcharlen(arg)) == -1 || len > MB_CUR_MAX)
	{
		e->iserror = TRUE;
		return ;
	}
	get_unicode(arg, c, len);
	e->flag.minus ? 0 : add_nchar(e, e->width - len, ' ');
	fill_buff(e, c, len);
	e->flag.minus ? add_nchar(e, e->width - len, ' ') : 0;
}
