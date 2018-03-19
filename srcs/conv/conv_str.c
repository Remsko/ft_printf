/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 17:29:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static inline int	ft_max(int x, int y)
{
	return (y > x ? y : x);
}

inline void			conv_str(t_env *e, char *arg)
{
	int len;

	if (arg == NULL)
		return (fill_buff(e, "(null)", 6));
	len = ft_max(0, ft_strlen(arg) - e->precision);
	e->flag.minus ? 0 : add_char(e, e->width - len, ' '); 
	fill_buff(e, arg, len);
	e->flag.minus ? add_char(e, e->width - len, ' ') : 0;
}
