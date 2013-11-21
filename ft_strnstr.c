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
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	int	k;
	int	i;

	if (str == 0 || find == 0)
		return (0);
	k = 0;
	i = 0;
	while (str[i] != '\0' && n--)
	{
		if (str[i] == find[k])
			k = k + 1;
		else
			k = 0;
		if (find[k] == '\0')
		{
			return ((char *)str + i - k + 1);
		}
		i++;
	}
	return (0);
}
