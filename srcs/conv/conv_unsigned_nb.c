/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:08:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 16:40:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline static void	printf_itoa_base(t_env *e, unsigned long long n, short base)
{
	char	str[U_NB_LENGTH_MAX];
	int		len;
	int		tmp;
	char	c;

	c = *e->format == 'X' ? 'A' : 'a';
	len = ft_unblen(n, base);
	tmp = len;
	while (len--)
	{
		str[len] = (n % base) + (n % base > 9 ? c - 10 : '0');
		n /= base;
	}
	fill_buff(e, str, tmp);
}

inline static int	get_zero(t_env *e)
{
	if (e->flag.zero == FALSE && e->precision <= 0)
		return (0);
	else if (e->flag.zero == TRUE && e->precision < e->width)
		return (e->precision < 0 ? e->width : e->precision);
	else
		return (e->precision);
}

inline static int	sharp_size(t_env *e, short base, unsigned long long arg)
{
	if (e->flag.sharp == TRUE && (arg != 0 || *e->format == 'p'))
		return (base == 8 ? 1 : 2);
	return (0);
}

inline static void	sharp_fill(t_env *e, unsigned long long arg, short base)
{
	if (e->flag.sharp == TRUE && (arg != 0 || *e->format == 'p'))
	{
		if (base == 8)
			fill_buff(e, "0", 1);
		else
			*e->format == 'X' ? fill_buff(e, "0X", 2) : fill_buff(e, "0x", 2);
	}
}

inline void			conv_unsigned(t_env *e, unsigned long long arg, short base)
{
	int len;
	int zero;
	int space;
	int	sharp;

	base == 10 ? e->flag.sharp = FALSE : 0;
	sharp = sharp_size(e, base, arg);
	len = ft_unblen(arg, base);
	zero = ft_intmax(0, get_zero(e) - len -
			(base == 8 || (e->flag.zero && e->width) ? sharp : 0));
	space = ft_intmax(0, e->width - (len + zero + e->flag.plus + sharp));
	if (e->flag.minus == FALSE)
		add_nchar(e, space, ' ');
	sharp_fill(e, arg, base);
	if (zero)
		add_nchar(e, zero, '0');
	if (e->precision == 0 && arg == 0 &&
			(e->flag.sharp == FALSE || (e->flag.sharp == TRUE && base == 16)))
		e->width ? fill_buff(e, " ", 1) : 0;
	else
		printf_itoa_base(e, arg, base);
	if (e->flag.minus == TRUE)
		add_nchar(e, space, ' ');
}
