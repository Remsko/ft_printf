/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:57:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 13:38:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"


#include "stdio.h"
inline void		conv_wstr(t_env *e, wchar_t *arg)
{
	char	*c;
	int		space;
	int		wstrlen;
	short	wcharlen;

	c = NULL;
	wcharlen = 0;
	if (arg == NULL)
		fill_buff(e, "(null)", 6);
	else
	{
		wstrlen = ft_wstrlen(arg);
		if (e->precision != -1 && e->precision < wstrlen)
			wstrlen = ft_wstrnlen(arg, e->precision);
		space = e->width - wstrlen;
		e->flag.minus ? 0 : add_nchar(e, space, ' ');
		while (*arg && (wstrlen -= wcharlen) > 0)
		{
			if ((wcharlen = ft_wcharlen(*arg)) == -1 || wcharlen > MB_CUR_MAX)
			{
				e->iserror = TRUE;
				return ;
			}
			if (wcharlen <= wstrlen)
			{
				c = (char[4]){0, 0, 0, 0};
				get_unicode(*arg, c, wcharlen);
				fill_buff(e, c, wcharlen);
			}
			arg++;
		}
		e->flag.minus ? add_nchar(e, space, ' ') : 0;
	}
}
