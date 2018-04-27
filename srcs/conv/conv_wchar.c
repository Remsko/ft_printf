/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:44:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 16:08:33 by rpinoit          ###   ########.fr       */
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

#include <stdio.h>

inline void			conv_wchar(t_env *e, wchar_t arg)
{
	char	*c;
	short	len;

	c = (char[4]){0, 0, 0, 0};
	if ((len = ft_wcharlen(arg)) == -1 || len > MB_CUR_MAX)
	{
		if (e->iserror == FALSE)
			write(1, (const void *)e->buf, (size_t)e->count);
		e->iserror = TRUE;
		return ;
	}
	get_unicode(arg, c, len);
	e->flag.minus ? 0 : add_nchar(e, e->width - len, ' ');
	fill_buff(e, c, len);
	e->flag.minus ? add_nchar(e, e->width - len, ' ') : 0;
}
