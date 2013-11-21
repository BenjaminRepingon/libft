/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 13:55:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strncmp (const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2++ && n--) 
	{
		if (*s1++ == 0)
			return (0);
	}
	return (*(unsigned char *) s1 - *(unsigned char *) --s2);
}