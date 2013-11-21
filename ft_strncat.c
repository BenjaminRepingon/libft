/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:44 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/20 11:50:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** With implementation **/
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	ft_strncpy(ft_strchr(dest, '\0'), (char *)src, n);
	return (dest);
}

/** Without implementation **/
/*
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *res;

	res = dest;
	while (*dest && n)
	{
		dest++;
		n--;
	}
	while (*dest++ = *src++);
	return (res);
}
*/