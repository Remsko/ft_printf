/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:56:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/17 11:57:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"
#include "stdio.h"

int     main(void)
{
	setlocale(LC_ALL,"");

	printf("%S\n", L"Á±≥");
	ft_printf("%S\n", L"Á±≥");
	return (0);
}