/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:06:48 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 15:06:50 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char *dp = (unsigned char *)src;
	unsigned char *sp = (unsigned char *)dest;

	if (!n)
		return dest;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));

	dp += n;
	sp += n;

	while (n--)
		*--sp = *--dp;

	return (dest);
}