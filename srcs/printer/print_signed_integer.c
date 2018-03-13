/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:55:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 14:43:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool	print_signed_integer(t_env *e, const char *f)
{
	int	jackie;

	jackie = va_arg(e->arg, int);
	ft_putnbr(jackie);
	while (jackie /= 10)
		++e->ret;
	(void)f;
	return (TRUE);
}
