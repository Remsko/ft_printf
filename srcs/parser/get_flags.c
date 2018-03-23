/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 13:46:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	get_flags(t_env *e)
{
	ft_bzero(&e->flag, sizeof(t_flag));
	while (1)
	{
		if (*e->format == '-')
			e->flag.minus = TRUE;
		else if (*e->format == '+')
			e->flag.plus = TRUE;
		else if (*e->format == ' ')
			e->flag.space = TRUE;
		else if (*e->format == '#')
			e->flag.sharp = TRUE;
		else if (*e->format == '0')
			e->flag.zero = TRUE;
		else
			break ;
		++e->format;
	}
	if (e->flag.minus == TRUE)
		e->flag.zero = FALSE;
}
