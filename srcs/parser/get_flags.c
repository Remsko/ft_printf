/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 18:28:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool	get_flags(t_env *e)
{
	while (1)
	{
		if (*e->format == '-' && e->flag.minus != TRUE)
			e->flag.minus = TRUE;
		else if (*e->format == '+' && e->flag.plus != TRUE)
			e->flag.plus = TRUE;
		else if (*e->format == ' ' && e->flag.space != TRUE)
			e->flag.space = TRUE;
		else if (*e->format == '#' && e->flag.sharp != TRUE)
			e->flag.sharp = TRUE;
		else if (*e->format == '0' && e->flag.zero != TRUE)
			e->flag.zero = TRUE;
		else
			break ;
		++e->format;
	}
	return (TRUE);
}
