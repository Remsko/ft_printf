/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:55:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 19:40:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static inline int	printf_itoa(int n, char *str)
{
	int	tmp;
	int	len;
	int	ret;

	len = (n <= 0);
	tmp = n;
	while (++len && tmp)
		tmp /= 10;
	ret = --len;
	tmp = (n < 0) ? -1 : 1;
	while (len)
	{
		str[--len] = (n % 10) * tmp + '0';
		n /= 10;
	}
	tmp < 0 ? *str = '-' : 0;
	return (ret);
}

t_bool				conv_integer(t_env *e)
{
	int arg;

	arg = va_arg(e->arg, int);
	e->count += printf_itoa(arg, &(e->buf[e->count]));
	return (TRUE);
}
