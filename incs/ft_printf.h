/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:27:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 19:08:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0 

# define PRINTF_SIZE 128

# include "../libft/libft.h"
# include "types.h"
# include "stdarg.h"
# include "stdlib.h"
# include "limits.h"

# include	"stdio.h"

typedef enum	s_len_enum
{
	none = 0,
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
}				t_len_enum;

typedef struct	s_env
{
	va_list		arg;
	char		buf[PRINTF_SIZE];
	char		*format;
	t_flag		flag;
	t_len_enum	length;
	int			width;
	int			count;
	int			fd;
}				t_env;

int		ft_printf(const char *format, ...);

t_bool	parse_arg(t_env *e);

t_bool  conv_integer(t_env *e);

t_bool	get_flags(t_env *e);

t_bool	get_width(t_env *e);

t_bool	get_precision(t_env *e);

t_bool	get_length(t_env *e);

t_bool	get_specifier(t_env *e);

void	fill_buff(t_env *e, char *src, int size);

#endif
