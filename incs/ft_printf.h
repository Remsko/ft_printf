/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:27:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/11 19:04:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "types.h"
# include "stdarg.h"
# include "stdlib.h"

# include	"stdio.h"

typedef struct	s_env
{
	t_arg_def	*def;
	va_list		arg;
	int			ret;
}				t_env;

int		ft_printf(const char *format, ...);

#endif
