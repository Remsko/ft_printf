/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_cast_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:41:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 18:11:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	chose_cast_unsigned_nb(t_env *e)
{
/*	if (*e->format == 'U' || *e->format == 'O'  || *e->format == 'X')
		e->length = none;*/
	if (e->length == none)
		conv_unsigned_nb(e, (uintmax_t)va_arg(e->arg, unsigned int));
	else if (e->length == hh)
		conv_unsigned_nb(e, (uintmax_t)((unsigned char)va_arg(e->arg, int)));
	else if (e->length == h)
		conv_unsigned_nb(e, (uintmax_t)((unsigned short)va_arg(e->arg, int)));
	else if (e->length == l)
		conv_unsigned_nb(e, (uintmax_t)va_arg(e->arg, unsigned long));
	else if (e->length == ll)
		conv_unsigned_nb(e, (uintmax_t)va_arg(e->arg, unsigned long long));
	else if (e->length == j)
		conv_unsigned_nb(e, va_arg(e->arg, uintmax_t));
	else if (e->length == z)
		conv_unsigned_nb(e, (uintmax_t)va_arg(e->arg, size_t));
}
