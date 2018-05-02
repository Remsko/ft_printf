/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:13:59 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/02 11:33:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"
#include "stdio.h"

int		main(void)
{
	setlocale(LC_ALL,"");

	wchar_t s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	int ret = printf("pf = %-15.5S et coco %S", s, s);
	printf("\nret pf = %d\n", ret);
	ret = printf("pf = %-15.8S et coco %S", s, s);
	printf("\nret pf = %d\n", ret);
	ret = printf("pf = %.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
    printf("\nret pf = %d\n", ret);
	ret = ft_printf("ft = %-15.5S et coco %S", s, s);
	printf("\nret ft = %d\n", ret);
	ret = ft_printf("ft = %-15.8S et coco %S", s, s);
	printf("\nret ft = %d\n", ret);
	ret = ft_printf("ft = %.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret ft = %d\n", ret);
	return (0);
}
/*
   int	main(void)
   {
   int i = 2147483647;
   long l = 2147483647;
   long long ll = 9223372036854775807;
   char c = 0;
   intmax_t im = 9223372036854775807;
   ft_printf("\n");
   ft_printf("%%\n");
   ft_printf("%d\n", 42);
   ft_printf("%d%d\n", 42, 41);
   ft_printf("%d%d%d\n", 42, 43, 44);
   ft_printf("%ld\n", l);
   ft_printf("%lld\n", ll);
   ft_printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
   ft_printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
   ft_printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
   ft_printf("%S %s %s\n", L"ݗݜशব","test", "test2");
   ft_printf("%s%s%s\n", "test", "test", "test");
   ft_printf("%C\n", 15000);
   }*/
