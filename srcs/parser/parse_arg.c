/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:15:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 18:28:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool		parse_arg(t_env *e)
{
	get_flags(e);
	get_width(e);
	get_precision(e);
	get_length(e);
	get_specifier(e);
	return (TRUE);
}
