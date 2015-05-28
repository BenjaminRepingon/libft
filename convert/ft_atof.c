/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:01:54 by rbenjami          #+#    #+#             */
/*   Updated: 2015/05/26 14:28:49 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	char	*tmp;
	int		i;
	float	value;
	float	divisor;

	tmp = (char *)str;
	value = ft_atoi(str);
	i = 0;
	while (tmp[i] && tmp[i] != '.')
		i++;
	i++;
	tmp += i;
	i = 0;
	divisor = 10;
	while (tmp[i] && (tmp[i] <= '9') && (tmp[i] > '0'))
	{
		if (value > 0)
			value += (float)(tmp[i] - '0') / divisor;
		else
			value -= (float)(tmp[i] - '0') / divisor;
		divisor *= 10;
		i++;
	}
	return (value);
}
