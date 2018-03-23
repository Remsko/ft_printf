/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:58:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 11:15:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_precision(t_env *e)
{
	e->precision = -1;
	if (*e->format == '.' && ++e->format)
	{
		e->precision = ft_atoi(e->format);
		while (ft_isdigit(*e->format))
			++e->format;
	}
}
