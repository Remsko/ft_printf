/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 15:27:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		conv_pourcent(t_env *e, void *arg)
{
	char c;

	(void)arg;
	c = e->flag.zero ? '0' : ' ';
	e->flag.minus ? 0 : add_nchar(e, e->width - 1, c);
	fill_buff(e, "%", 1);
	e->flag.minus ? add_nchar(e, e->width - 1, c) : 0;
}
