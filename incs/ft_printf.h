/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:27:23 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 15:12:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0 

# define NB_LENGTH_MAX 19
# define U_NB_LENGTH_MAX 20
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
	int			precision;
	int			count;
	int			new_size;
}				t_env;

int			ft_printf(const char *format, ...);

void		parse_arg(t_env *e);

void		conv_nb(t_env *e, intmax_t arg);

void		conv_unsigned(t_env *e, unsigned long long arg, short base);

void		conv_str(t_env *e, char *arg);

void		conv_char(t_env *e, int arg);

void		conv_ptr(t_env *e, void *arg);

void		conv_pourcent(t_env *e, void *arg);

void		get_flags(t_env *e);

void		get_width(t_env *e);

void		get_precision(t_env *e);

void		get_length(t_env *e);

void		get_specifier(t_env *e);

void		fill_buff(t_env *e, char *src, int size);

void		add_nchar(t_env *e, int n, char c);

void		chose_cast_nb(t_env *e);

void		chose_cast_unsigned_nb(t_env *e, short base);

#endif
