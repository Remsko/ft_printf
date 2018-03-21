/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:53:34 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/19 13:15:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(void *content, size_t content_size)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = (char**)content;
	(void)content_size;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
