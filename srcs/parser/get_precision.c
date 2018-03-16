/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:58:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 18:08:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static inline int	ft_max(int x, int y)
{
	return (y > x ? y : x);
}

t_bool				get_precision(t_env *e)
{
	if (*e->format == '.' && ++e->format)
	{
		e->width = ft_max(1, ft_atoi(e->format));
		while (ft_isdigit(*e->format))
			++e->format;
	}
	return (TRUE);
}
