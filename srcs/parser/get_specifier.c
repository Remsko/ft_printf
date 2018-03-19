/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_to_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:16:51 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 18:20:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_specifier(t_env *e)
{
	if (*e->format == 'd' || *e->format == 'i' || *e->format == 'D')
		return (chose_cast_nb(e));
	else if (*e->format == 's')
		return (conv_str(e, va_arg(e->arg, char *)));
	else if (*e->format == 'S')
		return ;
	else if (*e->format == 'p')
		return (conv_ptr(e, va_arg(e->arg, void *)));
	else if (*e->format == 'o')
		return ;
	else if (*e->format == 'O')
		return ;
	else if (*e->format == 'u' || *e->format == 'U')
		return (chose_cast_unsigned_nb(e));
	else if (*e->format == 'x')
		return ;
	else if (*e->format == 'X')
		return ;
	else if (*e->format == 'c')
		return (conv_char(e, va_arg(e->arg, int)));
	else if (*e->format == 'C')
		return ;
//		return (conv_char(e, va_arg(e->arg, wchar_t)));
}
