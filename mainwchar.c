/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:56:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 16:29:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"
#include "stdio.h"

int     main(void)
{
	wchar_t s[4];

	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';

	int ret = printf("%-4S", s);
	printf("\nprintf ret = %d\n", ret);
	ret = ft_printf("%-4S", s);
	printf("\nft_printf ret = %d\n", ret);
	return (0);
}
