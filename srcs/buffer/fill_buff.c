/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:26:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/03 16:51:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		fill_buff(t_env *e, char *src, int size)
{
	if (PRINTF_SIZE - e->index < size)
	{
		e->size_tmp = size;
		write(1, (const void *)e->buf, (size_t)e->index);
		e->index = 0;
		while (e->size_tmp > PRINTF_SIZE)
		{
			ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)PRINTF_SIZE);
			src += PRINTF_SIZE;
			write(1, (const void *)e->buf, (size_t)PRINTF_SIZE);
			e->size_tmp -= PRINTF_SIZE;
			e->count += PRINTF_SIZE;
		}
		ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)e->size_tmp);
		e->index += e->size_tmp;
		e->count += e->size_tmp;
	}
	else
	{
		ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)size);
		e->index += size;
		e->count += size;
	}
}
