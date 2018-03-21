/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:12:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 14:13:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unblen(uintmax_t n, uintmax_t base)
{
	int len;

	len = 1;
	while (n /= base)
		++len;
	return (len);
}