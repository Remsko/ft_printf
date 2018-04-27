/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:13:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 17:51:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline static void	printf_itoa(t_env *e, intmax_t n)
{
	char	str[NB_LENGTH_MAX];
	int		len;
	int		tmp;

	len = ft_nblen(n, 10);
	tmp = len;
	while (len--)
	{
		str[len] = (n % 10) * (n < 0 ? -1 : 1) + '0';
		n /= 10;
	}
	fill_buff(e, str, tmp);
}

inline static int	get_zero(t_env *e, intmax_t arg)
{
	if (e->flag.zero == FALSE && e->precision <= 0)
		return (0);
	else if (e->flag.zero == TRUE && e->precision < e->width)
		return (e->precision <= 0 ? e->width -
				(((e->flag.plus && arg >= 0) || arg < 0) || e->flag.space)
				: e->precision);
	else
		return (e->precision);
}

inline void			conv_nb(t_env *e, intmax_t arg)
{
	int len;
	int zero;
	int	space;

	len = ft_nblen(arg, 10);
	zero = ft_intmax(0, get_zero(e, arg) - len);
	space = ft_intmax(0, e->width - (len + zero +
				((e->flag.plus && arg >= 0) || arg < 0)));
	if ((e->flag.plus && arg >= 0) || arg < 0 || zero > 0 || space > 0)
		e->flag.space = FALSE;
	if (e->flag.minus == FALSE)
		add_nchar(e, space + (int)e->flag.space, ' ');
	if ((e->flag.plus && arg >= 0) || arg < 0)
		add_nchar(e, 1, (arg < 0 ? '-' : '+'));
	if (zero)
		add_nchar(e, zero, '0');
	if (e->precision == 0 && arg == 0)
		e->width ? fill_buff(e, " ", 1) : 0;
	else
		printf_itoa(e, arg);
	if (e->flag.minus == TRUE)
		add_nchar(e, space + (int)e->flag.space, ' ');
}
