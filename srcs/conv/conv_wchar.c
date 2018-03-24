/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:44:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/24 14:54:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	conv_wchar(t_env *e, wchar_t arg)
{
	char c;

	c = (char)arg;
	e->flag.minus ? 0 : add_nchar(e, e->width - 1, ' ');
	fill_buff(e, &c, 1);
	e->flag.minus ? add_nchar(e, e->width - 1, ' ') : 0;
}
