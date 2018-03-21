/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:08:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 18:54:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline static void  printf_itoa_base(t_env *e, uintmax_t n, uintmax_t base)
{
	char    str[U_NB_LENGTH_MAX];
	int     len;
	int     tmp;

	len = ft_nblen(n, base);
	tmp = len;
	while (len--)
	{
		str[len] = (n % 10) + (n % base < 10 ? '0' : 'A' - 10);
		n /= 10;
	}
	fill_buff(e, str, tmp);
}

inline static int   get_zero(t_env *e, uintmax_t arg)
{
	if (e->flag.zero == FALSE && e->precision <= 0)
		return (0);
	else if (e->flag.zero == TRUE && e->precision < e->width)
		return (e->precision <= 0 ? e->width -
				((e->flag.plus && arg) || e->flag.space) : e->precision);
	else
		return (e->precision);
}

inline void	conv_unsigned_nb(t_env *e, uintmax_t arg, uintmax_t base)
{
	int len;
	int zero;
	int space;

	len = ft_unblen(arg, base);
	zero = ft_intmax(0, get_zero(e, arg) - len);
	space = ft_intmax(0, e->width - (len + zero + e->flag.plus));
	if (e->flag.plus || zero > 0 || space > 0)
		e->flag.space = FALSE;
	if (e->flag.minus == FALSE)
		add_nchar(e, space + (int)e->flag.space, ' ');
	if (e->flag.plus)
		add_nchar(e, 1, '+');
	if (zero)
		add_nchar(e, zero, '0');
	if (e->precision == 0 && arg == 0)
		e->width ? fill_buff(e, " ", 1) : 0;
	else
		printf_itoa_base(e, arg, base);
	if (e->flag.minus == TRUE)
		add_nchar(e, space + (int)e->flag.space, ' ');
}
