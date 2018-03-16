/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:55:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 13:48:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

t_bool	conv_integer(t_env *e)
{
/*	long long	i;
	int			tmp;

	i = va_arg(e->arg, long long);
	if (i > LONG_MAX || i < LONG_MIN)
	{
		e->ret += 2;
		ft_putnbr(-1);
		return (TRUE);
	}
	if ((tmp = (int)i) < 0 && (e->ret += 2))
		e->flag = (t_flag){ .space = FALSE, .plus = FALSE};
	else
		++e->ret;
	while (tmp /= 10)
		++e->ret;
	if (e->flag.plus == TRUE && (e->flag.space = FALSE) == 0 && (++e->ret))
		ft_putchar('+');
	if (e->flag.space == TRUE && (++e->ret))
		ft_putchar(' ');
	ft_putnbr((int)i);*/
	(void)e;
	return (TRUE);
}
