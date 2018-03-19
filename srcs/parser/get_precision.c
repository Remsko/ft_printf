/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:58:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 17:47:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"
/*
static inline int	ft_max(int x, int y)
{
	return (y > x ? y : x);
}
*/
inline void			get_precision(t_env *e)
{
	e->precision = 0;
	if (*e->format == '.' && ++e->format)
	{
		e->precision = ft_atoi(e->format);//ft_max(1, ft_atoi(e->format));
		while (ft_isdigit(*e->format))
			++e->format;
	}
}
