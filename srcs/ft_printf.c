/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:38:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 20:50:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/*
** algo + rapide ? = chercher le % (en comptant)
** afficher jusqu'au % avec un write du comptant
** afficher le contenu du % puis recommencer
*/

t_bool	pourcent_pair(const char *f, int *i)
{
	int tmp;

	tmp = *i;
	while (f[tmp] == ' ')
			++tmp;
	if (f[tmp] == '%')
	{
		*i = tmp;
		return (TRUE);
	}
	else
		return (FALSE);
}

int		ft_printf(const char *format, ...)
{
	t_env	e;

	e = (t_env){ .index = 0, .ret = 0, .parser_ret = TRUE};
	va_start(e.arg, format);
	while (format[e.index] != '\0')
	{
		if (format[e.index] == '%' && (++e.index))
		{
			if (format[e.index] == '\0')
				break ;
			if (pourcent_pair(format, &e.index) && (++e.ret) && (++e.index))
				ft_putchar('%');
			else if (parse_arg(&e, format) == FALSE)
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

