/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:59:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 19:58:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_length(t_env *e)
{
	e->length = none;
	while (1)
	{
		if (*e->format == 'h')
			e->length = (e->format[1] == 'h' && ++e->format) ? hh : h;
		else if (*e->format == 'l')
			e->length = (e->format[1] == 'l' && ++e->format) ? ll : l;
		else if (*e->format == 'j')
			e->length = j;
		else if (*e->format == 'z')
			e->length = z;
		else
			break ;
		++e->format;
	}
}
