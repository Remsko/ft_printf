/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:13:59 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/19 18:15:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"

int		main(void)
{
	printf("%\n", "delicieux");
	int ret = printf("printf %10.2s is a string\n", "this");
	ft_putchar('\n');
	printf("printf ret = %d\n", ret);
	ft_putchar('\n');
	ret = ft_printf("ft_printf %10.2s is a string\n", "this");
	ft_putchar('\n');
	printf("ft_printf ret = %d\n", ret);
	ft_putchar('\n');
	return (0);
}
