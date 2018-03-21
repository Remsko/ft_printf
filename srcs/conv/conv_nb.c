/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:13:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 16:32:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"
#define SIGN_MULT n < 0 ? -1 : 1
#define SIGN_COND (e->flag.plus && arg >= 0) || arg < 0
#define SIGN_CHOSE arg < 0 ? '-' : '+'

inline static void	printf_itoa(t_env *e, intmax_t n)
{
	int		len;
	char	c;

	len = ft_nblen(n, 10);
	while (len)
	{
		c = (n % 10) * (SIGN_MULT) + '0';
		n /= 10;
		fill_buff(e, &c, 1);
	}
}

inline static int 	get_zero(t_env *e)
{
	if (e->flag.zero == FALSE && e->precision <= 0)
		return (0);
	else if (e->flag.zero == TRUE && e->precision < e->width)
		return (e->precision);
	else
		return (e->precision);
}

inline void			conv_nb(t_env *e, intmax_t arg)
{
	int len;
	int zero;
	int	space;

	len = ft_nblen(arg, 10);
	zero = ft_intmax(0, get_zero(e) - len);
	space = ft_intmax(0, e->width - (len + zero + (SIGN_COND)));
	if (e->flag.minus == FALSE)
		add_nchar(e, space, ' ');
	if (SIGN_COND)
		add_nchar(e, 1, SIGN_CHOSE);
	if (zero)
		add_nchar(e, zero, '0');
	printf_itoa(e, arg);
	if (e->flag.minus == TRUE)
		add_nchar(e, space, ' ');
}
