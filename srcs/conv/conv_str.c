/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 16:04:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		conv_str(t_env *e, char *arg)
{
	int len;

	if (arg == NULL && (len = 6))
		arg = "(null)";
	else
		len = ft_strlen(arg);
	if (e->precision > 0)
		len = e->precision < len ? e->precision : len;
	else if (e->precision == 0)
		len = 0;
	e->flag.minus ? 0 : add_nchar(e, e->width - len, ' ');
	fill_buff(e, arg, len);
	e->flag.minus ? add_nchar(e, e->width - len, ' ') : 0;
}
