/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:56:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 13:25:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"
#include "stdio.h"

int     main(void)
{

	setlocale(LC_ALL,"en_US.UTF-8");

	int ret = printf("%15.4S", L"我是一只猫。");
	printf("\nprintf ret = %d\n", ret);
	ret = ft_printf("%15.4S", L"我是一只猫。");
	printf("\nft_printf ret = %d\n", ret);
	return (0);
}
