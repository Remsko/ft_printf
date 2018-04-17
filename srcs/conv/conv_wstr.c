/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:57:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/17 16:54:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

inline void		conv_wstr(t_env *e, wchar_t *arg)
{
	t_flag tmp;

	tmp = e->flag;
	e->width = 1;
	ft_bzero(&e->flag, sizeof(t_flag));
	if (arg == NULL)
	{
		fill_buff(e, "(null)", 6);
		return ;
	}
	while (*arg)
	{
		conv_wchar(e, *arg);
		arg++;
	}
}
