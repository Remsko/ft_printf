/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:34:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 16:36:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void	conv_ptr(t_env *e, void *ptr)
{
	e->flag.sharp = TRUE;
	conv_unsigned(e, (unsigned long long)ptr, 16);
}
