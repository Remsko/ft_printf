/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_to_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:16:51 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/24 11:58:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_specifier(t_env *e)
{
	if (*e->format == 'd' || *e->format == 'i' || *e->format == 'D')
		chose_cast_nb(e);
	else if (*e->format == 's')
		conv_str(e, va_arg(e->arg, char *));
	else if (*e->format == 'S')
		return ;
	else if (*e->format == 'p')
		conv_ptr(e, va_arg(e->arg, void *));
	else if (*e->format == 'o' || *e->format == 'O')
		chose_cast_unsigned_nb(e, 8);
	else if (*e->format == 'u' || *e->format == 'U')
		chose_cast_unsigned_nb(e, 10);
	else if (*e->format == 'x' || *e->format == 'X')
		chose_cast_unsigned_nb(e, 16);
	else if (*e->format == 'c')
		e->length == l ? 0 : conv_char(e, va_arg(e->arg, int));
	else if (*e->format == 'C')
		conv_wchar(e, va_arg(e->arg, wchar_t));
	else if (*e->format == '%')
		conv_pourcent(e, va_arg(e->arg, void *));
	else
		fill_buff(e, e->format, 1);
}
