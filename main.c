/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:13:59 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/16 19:15:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"

int		main(void)
{

	/*	int ret = ft_printf("ft_printf %d\n", 42);
		printf("ft_printf ret = %d\n", ret);

		ret = ft_printf("%%%%");
		printf("ft_printf ret = %d\n", ret);

		ret = ft_printf("%+  d\n", 42);
		printf("ft_printf ret = %d\n", ret);
		*/
	char str[100] = "%d\n";
	printf("test = %s\n\n", str);

	int ret = printf("%d\n", 50);
	ft_putchar('\n');
	printf("printf ret = %d\n", ret);
	ft_putchar('\n');
	ret = ft_printf("ft_printf = %d\n", -50);
	ft_putchar('\n');
	printf("ft_printf ret = %d\n", ret);
	ft_putchar('\n');
	return (0);
}
