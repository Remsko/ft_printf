/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:27:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 15:46:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"
# include "types.h"
# include "stdarg.h"
# include "stdlib.h"

# include	"stdio.h"

typedef struct	s_env
{
	va_list		arg;
	int			index;
	int			ret;
	t_bool		parser_ret;
}				t_env;

int		ft_printf(const char *format, ...);

t_bool	parse_arg(t_env *e, const char *f);

t_bool  get_specifier(t_env *e, const char *f);

t_bool  print_signed_integer(t_env *e, const char *f);

#endif
