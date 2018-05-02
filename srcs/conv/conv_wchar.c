/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:44:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 18:03:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void			conv_wchar(t_env *e, wchar_t arg)
{
	char	*c;
	short	len;

	c = (char[4]){0, 0, 0, 0};
	if ((len = ft_wcharlen(arg)) == -1 || len > MB_CUR_MAX)
	{
		if (MB_CUR_MAX == 1 && (arg >= 127 && arg <= 255))
		{
			e->flag.minus ? 0 : add_nchar(e, e->width - 1, ' ');
			c[0] = (char)arg;
			fill_buff(e, c, 1);
			e->flag.minus ? add_nchar(e, e->width - 1, ' ') : 0;
		}
		else
		{
			if (e->iserror == FALSE)
				write(1, e->buf, (e->count - e->uselesserror));
			e->iserror = TRUE;
		}
		return ;
	}
	get_unicode(arg, c, len);
	e->flag.minus ? 0 : add_nchar(e, e->width - len, ' ');
	fill_buff(e, c, len);
	e->flag.minus ? add_nchar(e, e->width - len, ' ') : 0;
}
