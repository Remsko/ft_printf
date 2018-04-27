/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:57:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 18:12:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		conv_wstr(t_env *e, wchar_t *arg)
{
	char	*c;
	int		space;
	int		strlen;
	short	charlen;

	c = NULL;
	if (arg == NULL)
	{
		fill_buff(e, "(null)", 6);
		return ;
	}
	else
	{
		strlen = ft_wstrlen(arg); // can be remove
		if (e->precision != -1)
			strlen = strlen > e->precision ? strlen : e->precision;
		space = e->width - strlen;
		e->flag.minus ? 0 : add_nchar(e, space, ' ');
		while (*arg && strlen > 0)
		{
			c = (char[4]){0, 0, 0, 0};
			if ((charlen = ft_wcharlen(*arg)) == -1 || charlen > MB_CUR_MAX)
			{
				e->iserror = TRUE;
				return ;
			}
			get_unicode(*arg, c, charlen);
			fill_buff(e, c, charlen);
			strlen -= charlen;
			arg++;
		}
		e->flag.minus ? add_nchar(e, space, ' ') : 0;
	}
}
