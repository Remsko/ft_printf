/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool	get_flags(t_env *e)
{
	while (1)
	{
		if (*e->format == '-' /*&& e->flag.minus != TRUE*/)
			e->flag.minus = TRUE;
		else if (*e->format == '+' /*&& e->flag.plus != TRUE*/)
			e->flag.plus = TRUE;
		else if (*e->format == ' ' /*&& e->flag.space != TRUE*/)
			e->flag.space = TRUE;
		else if (*e->format == '#' /*&& e->flag.sharp != TRUE*/)
			e->flag.sharp = TRUE;
		else if (*e->format == '0' /*&& e->flag.zero != TRUE*/)
			e->flag.zero = TRUE;
		else
			break ;
		++e->format;
	}
	(e->flag.plus || e->flag.minus) ? e->flag.space = FALSE : 0;
	e->flag.minus ? e->flag.zero = FALSE : 0;
	return (TRUE);
}
