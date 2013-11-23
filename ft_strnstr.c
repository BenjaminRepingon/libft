/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 13:55:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	const	char	*sp;
	size_t		findL;
	size_t		cmp;

	sp = str;
	findL = ft_strlen(find);
	if (findL == 0)
		return ((char*)str);
	while (*sp && sp + findL <= str + n)
	{
		cmp = ft_strncmp(sp + 1, find + 1, findL - 1);

		if (*sp == *find && cmp == 0)
			return ((char*)sp);
		sp++;
	}
	return (0);
}
