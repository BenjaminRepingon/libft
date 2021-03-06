/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:01:54 by rbenjami          #+#    #+#             */
/*   Updated: 2015/05/28 15:44:17 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	char	*tmp;
	int		i;
	float	value;
	float	divisor;
	int		negative;

	tmp = (char *)str;
	value = ft_atoi(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (negative = (*str == '-')))
		str++;
	i = 0;
	while (tmp[i] && tmp[i] != '.')
		i++;
	tmp += i + 1;
	i = 0;
	divisor = (negative) ? -10 : 10;
	while (tmp[i] && (tmp[i] <= '9') && (tmp[i] >= '0'))
	{
		value += (float)(tmp[i] - '0') / divisor;
		divisor *= 10;
		i++;
	}
	return (value);
}
