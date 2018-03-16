/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_to_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:16:51 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 19:38:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool	get_specifier(t_env *e)
{
	if (*e->format == 'd' || *e->format == 'i' || *e->format == 'D')
		return (conv_integer(e));
	return (TRUE);
}
