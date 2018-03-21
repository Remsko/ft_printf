/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 14:01:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		**tab;
	char		**ret;

	if (!s || !(tab = (char**)malloc(sizeof(*tab) * \
					(ft_count_words(s, c) + 1))))
		return (NULL);
	ret = tab;
	while (*s)
	{
		if (*s == c)
			++s;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				++len;
			if (!(*tab++ = ft_strndup(s, len)))
				return (NULL);
			s += len;
		}
	}
	*tab = NULL;
	return (ret);
}
