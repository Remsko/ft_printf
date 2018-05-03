/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:26:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/03 18:10:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		fill_buff(t_env *e, char *src, int size)
{
	int size_tmp;

	size_tmp = 0;
	if ((e->new_size = PRINTF_SIZE - e->index) < size)
	{
		size_tmp = size;
		write(1, (const void *)e->buf, (size_t)e->index);
		e->index = 0;
		while (size_tmp > PRINTF_SIZE)
		{
			ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)PRINTF_SIZE);
			src += PRINTF_SIZE;
			write(1, (const void *)e->buf, (size_t)PRINTF_SIZE);
			size_tmp -= PRINTF_SIZE;
			e->count += PRINTF_SIZE;
		}
		ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)size_tmp);
		e->index += size_tmp;
		e->count += size_tmp;
	}
	else
	{
		ft_memcpy((void *)(&e->buf[e->index]), (const void *)src, (size_t)size);
		e->index += size;
		e->count += size;
	}
}
