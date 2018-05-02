/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:57:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 16:32:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

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
		e->width = 0;
		e->flag.minus ? 0 : add_nchar(e, space, ' ');
		while (*arg && wstrlen > 0)
		{
			if ((wcharlen = ft_wcharlen(*arg)) == -1 || wcharlen > MB_CUR_MAX)
			{
				if (MB_CUR_MAX == 1 && *arg >= 127 && *arg <= 255)
					wcharlen = 1;
				else
				{
					e->iserror = TRUE;
					return ;
				}
			}
			if (MB_CUR_MAX == 1 && *arg > 255 && (e->iserror = TRUE))
				return ;
			if (wcharlen <= wstrlen)
				conv_wchar(e, *arg);
			wstrlen -= wcharlen;
			arg++;
		}
		e->flag.minus ? add_nchar(e, space, ' ') : 0;
	}
}
