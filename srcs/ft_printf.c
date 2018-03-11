/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:38:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/11 18:56:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env	env;
	int i = 0;

	env.def = (t_arg_def*)malloc(sizeof(t_arg_def*));
	va_start(env.arg, format);
	while (i--)
	{
		env.def->arg = va_arg(env.arg, char *);
	}
	free(env.def);
	va_end(env.arg);
	(void)format;
	return (0);
}
