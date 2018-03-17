/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:38:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/17 16:26:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
/*
static inline t_bool	pourcent_pair(char **f)
{
	char *tmp;

	tmp = *f;
	while (*tmp == ' ')
		++tmp;
	if (*tmp == '%')
	{
		*f = tmp;
		return (TRUE);
	}
	return (FALSE);
}*/

int						ft_printf(const char *format, ...)
{
	t_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	e.format = (char *)format;
	va_start(e.arg, format);
	while (*e.format != '\0')
	{
		if (*e.format == '%' && ++e.format)
		{
			if (*e.format == '\0')
				break ;
	/*		else if (pourcent_pair(&e.format) == TRUE) // NEED A REWORK
				fill_buff(&e, e.format, 1);*/
			else if (parse_arg(&e) == FALSE)
				return (-1);
		}
		else
			fill_buff(&e, e.format, 1);
		++e.format;
	}
	/*e.count = */write(e.fd, (const void *)e.buf, (size_t)e.count);
	va_end(e.arg);
	return (e.count);
}
