/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:54:35 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 20:50:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	get_flag(t_env *e, const char *f)
{
	while (f[e->index] == '-' || f[e->index] == '+' || f[e->index] == ' ')
	{
		if (f[e->index] == '-' && (e->flag.minus = TRUE))
			++e->index;
		else if (f[e->index] == '+' && (e->flag.plus = TRUE))
			++e->index;
		else if (f[e->index] == ' ' && (e->flag.space = TRUE))
			++e->index;
	}
}
