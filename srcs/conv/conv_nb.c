/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:13:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 17:32:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static inline void	printf_itoa(char *str, intmax_t neg, intmax_t nb, int len)
{
	while (len)
	{
		str[--len] = (nb % 10) * ((nb < 0) ? -1 : 1) + '0';
		nb /= 10;
	}
	neg < 0 ? *str = '-' : 0;
}

static inline void	add_char_nb(t_env *e, int size)
{
	while (size > 0)
	{
		fill_buff(e, e->flag.zero ? "0" : " ", 1);
		--size;
	}
}

static inline void	modif_sign(t_env *e, int *len, intmax_t *tmp, intmax_t arg)
{
	if (e->flag.plus && arg >= 0)
	{
		--e->width;
		if (e->width < *len || e->flag.zero)
		{
			fill_buff(e, "+", 1);
			e->flag.plus = FALSE;
		}
	}
	else if (e->flag.zero && arg < 0)
	{
		fill_buff(e, "-", 1);
		--e->width;
		*len -= 1;
		*tmp = 1;
	}
	else if (e->flag.space)
	{
		--e->width;
		fill_buff(e, " ", 1);
	}
}

inline void			conv_nb(t_env *e, intmax_t arg)
{
	intmax_t	tmp;
	int			len;

	tmp = arg;
	len = (arg <= 0);
	while (++len && tmp)
		tmp /= 10;
	len--;
	(e->precision - len > 0) ? len += e->precision - len + (arg < 0) : 0;
	(e->width - len >= 0 && e->precision) ? e->flag.zero = FALSE + (arg < 0) : 0;
	tmp = (arg < 0) ? -1 : (e->flag.plus && arg >= 0);
	(e->flag.zero || tmp == 1) ? modif_sign(e, &len, &tmp, arg) : 0;
	e->flag.minus == FALSE ? add_char_nb(e, e->width - len) : 0;
	(arg >= 0 && e->flag.space && e->width - len < 0) ? fill_buff(e, " ", 1) : 0;
	(arg >= 0 && e->flag.plus == TRUE) ? fill_buff(e, "+", 1) : 0;
	printf_itoa(&(e->buf[e->count]), tmp, arg, len);
	e->count += len;
	e->flag.minus == TRUE ? add_char_nb(e, e->width - len) : 0;
}
