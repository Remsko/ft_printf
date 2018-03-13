/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:38:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 15:46:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env	e;

	va_start(e.arg, format);
	while (format[e.index] != '\0')
	{
		if (format[e.index] == '%')
		{
			if (parse_arg(&e, format) == FALSE)
				return (-1);
		}
		else
		{
			ft_putchar(format[e.index++]);
			++e.ret;
		}
	}
	va_end(e.arg);
	return (e.ret);
}