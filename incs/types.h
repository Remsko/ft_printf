/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:34:53 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/11 16:59:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "ft_printf.h"

typedef enum	s_conv_enum
{
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C
}				t_conv_enum;

typedef struct			s_arg_def
{
	t_conv_enum			letter; //conversion
	void				*arg;	//argument en question
	//flags #0-+ et ' '
	//taille minimum
	//precision
	//flags hh h l ll j z
	struct s_arg_def	*next;
}						t_arg_def;

#endif
