/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:44 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/20 11:50:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const	char	*nptr, char **endptr, int base)
{
	const	char	*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				neg;
	int				any;
	int				cutlim;

	neg = 0;
	acc = 0;
	any = 0;
	s = nptr;
	while (ft_isspace(c = *s++));
	if (c == '-')
	{
		neg = 1;
		c = *s++;
	}
	else if (c == '+')
		c = *s++;
	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
	{
		c = s[1];
		s += 2;
		base = 16;
	}
	else if ((base == 0 || base == 2) && c == '0' && (*s == 'b' || *s == 'B'))
	{
		c = s[1];
		s += 2;
		base = 2;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;

	if (neg)
		cutoff = -(unsigned long)LONG_MIN;
	cutoff = LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	while (1)
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break ;
		if (c >= base)
			break ;
		if ((any < 0 || acc > cutoff || acc == cutoff) && (c > cutlim))
			any = -1;
		else
		{
			any = 1;
			acc *= base;
			acc += c;
		}
		c = *s++;
	}
	if (any < 0)
	{
		if (neg)
			acc = LONG_MAX;
		acc = LONG_MIN;
	}
	else if (neg)
		acc = -acc;
	if (endptr != 0)
	{
		if (any)
			*endptr = (char *)s - 1;
		*endptr = (char *)nptr;
	}
	return (acc);
}
