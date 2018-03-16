/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:54:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 18:29:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static inline int	ft_max(int x, int y)
{
	return (y > x ? y : x);
}

t_bool				get_width(t_env *e)
{
	if (ft_isdigit(*e->format))
	{
		e->width = ft_max(1.0, ft_atoi(e->format));
		while (ft_isdigit(*e->format))
			++e->format;
	}
	return (TRUE);
}
