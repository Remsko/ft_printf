/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:38:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 18:10:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int						ft_printf(const char *format, ...)
{
	t_env	e;

	e = (t_env){ .format = (char *)format, .count = 0, .uselesserror = 0,
		.iserror = FALSE};
	va_start(e.arg, format);
	while (*e.format != '\0')
	{
		if (*e.format == '%' && ++e.format)
		{
			if (*e.format == '\0')
				break ;
			parse_arg(&e);
			e.uselesserror = 0;
		}
		else if (++e.uselesserror)
		{
			fill_buff(&e, e.format, 1);
		}
		++e.format;
	}
	if (e.iserror == TRUE)
		return (-1);
	write(1, (const void *)e.buf, (size_t)e.count);
	va_end(e.arg);
	return (e.count);
}
