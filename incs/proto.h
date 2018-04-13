/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:05:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/13 16:06:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "ft_printf.h"

int		ft_printf(const char *format, ...);

void	parse_arg(t_env *e);

void	conv_nb(t_env *e, intmax_t arg);

void	conv_unsigned(t_env *e, unsigned long long arg, short base);

void	conv_str(t_env *e, char *arg);

void	conv_wstr(t_env *e, wchar_t *arg);

void	conv_char(t_env *e, int arg);

void	conv_wchar(t_env *e, wchar_t arg);

void	conv_ptr(t_env *e, void *arg);

void	conv_pourcent(t_env *e, void *arg);

void	get_flags(t_env *e);

void	get_width(t_env *e);

void	get_precision(t_env *e);

void	get_length(t_env *e);

void	get_specifier(t_env *e);

void	fill_buff(t_env *e, char *src, int size);

void	add_nchar(t_env *e, int n, char c);

void	chose_cast_nb(t_env *e);

void	chose_cast_unsigned_nb(t_env *e, short base);

#endif
