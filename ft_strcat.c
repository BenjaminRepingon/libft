/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:44 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/20 11:50:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** With implementation **/
char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(ft_strchr(dest, '\0'), (char *)src);
	return dest;
}


/** Without implementation **/
/*
char	*ft_strcat(char *dest, const char *src)
{
	char *res;

	res = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++);
	return (res);
}
*/
