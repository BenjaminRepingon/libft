/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:01:32 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 11:25:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Itératif **/
/*
char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	if (dest != 0 || src != 0)
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
*/
#include <stdio.h>
/** Récursif **/
char	*ft_strcpy(char *dest, const char *src)
{
	if(*src == '\0') 
	{
		*dest = *src;
		return (dest);
	}
	else
	{
		*dest = *src;
		return (ft_strcpy(dest + 1, src + 1));
	}
}

int main(int argc, char const *argv[])
{
	char    dest[50] = {0};
    char    dest2[50] = {0};
 
    strcpy(dest, "Hello foo");
    printf("%s\n", dest);
    ft_strcpy(dest, "Hello foo");
    printf("%s\n", dest);
	return 0;
}
