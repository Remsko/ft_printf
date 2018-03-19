/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:02:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 17:29:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	conv_char(t_env *e, int arg)
{
	char c;

	c = (char)arg;
	e->flag.minus ? 0 : add_char(e, e->width - 1, ' ');
	fill_buff(e, &c, 1);
	e->flag.minus ? add_char(e, e->width - 1, ' ') : 0;
}
