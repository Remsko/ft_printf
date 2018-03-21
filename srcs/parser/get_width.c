/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:54:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 20:28:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_width(t_env *e)
{
	e->width = 0;
	if (ft_isdigit(*e->format))
	{
		e->width = ft_atoi(e->format);
		while (ft_isdigit(*e->format))
			++e->format;
	}
}
