/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_cast_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:41:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 11:10:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	chose_cast_unsigned_nb(t_env *e, short base)
{
	if (*e->format == 'U' || *e->format == 'O' || *e->format == 'X')
		e->length = l;
	if (e->length == none)
		conv_unsigned(e,
				(unsigned long long)va_arg(e->arg, unsigned int), base);
	else if (e->length == hh)
		conv_unsigned(e,
				(unsigned long long)((unsigned char)va_arg(e->arg, int)), base);
	else if (e->length == h)
		conv_unsigned(e, (unsigned long long)
				((unsigned short)va_arg(e->arg, int)), base);
	else if (e->length == l)
		conv_unsigned(e,
				(unsigned long long)va_arg(e->arg, unsigned long), base);
	else if (e->length == ll)
		conv_unsigned(e, va_arg(e->arg, unsigned long long), base);
	else if (e->length == j)
		conv_unsigned(e, (unsigned long long)va_arg(e->arg, uintmax_t), base);
	else if (e->length == z)
		conv_unsigned(e, (unsigned long long)va_arg(e->arg, size_t), base);
}
