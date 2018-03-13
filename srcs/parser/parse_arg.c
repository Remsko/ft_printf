/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:15:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/13 19:53:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

t_bool		parse_arg(t_env *e, const char *f)
{
	get_flag(e, f);
	if (get_specifier(e, f) == FALSE)
		return (FALSE);
	return (TRUE);
}
