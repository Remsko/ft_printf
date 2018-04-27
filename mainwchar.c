/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:56:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/04/27 17:24:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"
#include "stdio.h"

int     main(void)
{

	int ret = printf("%.5s", NULL);
	printf("\nprintf ret = %.0s\n", NULL);
	ret = ft_printf("%.5s", NULL);
	printf("\nft_printf ret = %.0s\n", NULL);
	return (0);
}
