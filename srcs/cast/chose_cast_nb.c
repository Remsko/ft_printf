/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_cast_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:41:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 18:22:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	chose_cast_nb(t_env *e)
{
	*e->format == 'D' ? e->length = l : 0;
	if (e->length == none)
		conv_nb(e, (intmax_t)va_arg(e->arg, int));
	else if (e->length == hh)
		conv_nb(e, (intmax_t)((char)va_arg(e->arg, int)));
	else if (e->length == h)
		conv_nb(e, (intmax_t)((short)va_arg(e->arg, int)));
	else if (e->length == l)
		conv_nb(e, (intmax_t)va_arg(e->arg, long));
	else if (e->length == ll)
		conv_nb(e, (intmax_t)va_arg(e->arg, long long));
	else if (e->length == j)
		conv_nb(e, va_arg(e->arg, intmax_t));
	else if (e->length == z)
		conv_nb(e, (intmax_t)va_arg(e->arg, size_t));
}
