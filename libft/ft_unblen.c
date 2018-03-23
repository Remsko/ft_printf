/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:12:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/23 10:45:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unblen(uintmax_t n, short base)
{
	int len;

	len = 1;
	while (n /= (uintmax_t)base)
		++len;
	return (len);
}
