/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:34:53 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 13:50:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "ft_printf.h"

typedef enum	e_len_enum
{
	none = 0,
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
}				t_len_enum;

typedef struct	s_flag
{
	t_bool	plus;
	t_bool	minus;
	t_bool	space;
	t_bool	sharp;
	t_bool	zero;
}				t_flag;

typedef struct	s_env
{
	va_list		arg;
	char		buf[PRINTF_SIZE];
	char		*format;
	t_flag		flag;
	t_len_enum	length;
	int			width;
	int			precision;
	int			count;
	int			new_size;
	t_bool		iserror;
	int			uselesserror;
}				t_env;

#endif
