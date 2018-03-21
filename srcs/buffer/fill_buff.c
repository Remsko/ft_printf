/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:26:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 16:33:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		fill_buff(t_env *e, char *src, int size)
{
//	if ((e->new_size = PRINTF_SIZE - e->count) < size)
//		return ;
	ft_memcpy((void *)(&e->buf[e->count]), (const void *)src, (size_t)size);
	e->count += size;
}
