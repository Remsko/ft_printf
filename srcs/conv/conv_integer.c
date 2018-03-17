/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:56:20 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/17 17:24:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static inline void	printf_itoa(int neg, int n, char *str, int len)
{
	neg = (n < 0) ? -1 : 1;
	while (len)
	{
		str[--len] = (n % 10) * neg + '0';
		n /= 10;
	}
	neg < 0 ? *str = '-' : 0;
}
/*
static inline void	add_char(t_env *e, int size)
{
	while (size > 0)
	{
		fill_buff(e, e->flag.zero ? "0" : " ", 1);
		--size;
	}
}
*/
t_bool				conv_integer(t_env *e)
{
	int		arg;
	int		len;
	int		tmp;

	arg = va_arg(e->arg, int);
	tmp = arg;
	len = (arg <= 0);
	while (++len && tmp)
		tmp /= 10;
	/*if (e->flag.zero && e->flag.plus)
	{
		fill_buff(e, "+", 1);
		e->flag.plus = FALSE;
	}
	e->flag.minus == FALSE ? add_char(e, e->width - len - 1) : 0; */
	(arg >= 0 && e->flag.space == TRUE) ? fill_buff(e, " ", 1) : 0;
	(arg >= 0 && e->flag.plus == TRUE) ? fill_buff(e, "+", 1) : 0;
	printf_itoa(tmp, arg, &(e->buf[e->count]), --len);
/*	e->flag.minus == TRUE ? add_char(e, e->width - len - 1) : 0;*/
	e->count += len;
	return (TRUE);
}
