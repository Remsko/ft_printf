/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:26:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/17 18:43:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/*
**  NEED TO CODE THISE CASE :
**  if ((int new_size = PRINTF_SIZE - e->count) < size)
*/

inline void		fill_buff(t_env *e, char *src, int size)
{
	ft_memcpy((void *)(&e->buf[e->count]), (const void *)src, (size_t)size);
	e->count += size;
}
