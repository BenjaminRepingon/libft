/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:44 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/20 11:50:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/** Itératif **/
/*
char *ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;
	if (dest != 0 || src != 0)
	{
		i = 0;
		while (src[i] != '\0' && i != n)
		{
			dest[i] = src[i];
			i++;
		}
		if (src[i] == '\0')
			dest[i] = '\0';
		return (dest);
	}
	return (0);
}
*/

/** Récursif **/
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	return strncpy(dest, src, n);
	/*
	if(*src == '\0' || n == 0) 
	{
		*dest = *src;
		return (dest);
	}
	else
	{
		*dest = *src;
		return (ft_strncpy(dest++, src++, n--));
	}*/
}
/*
int main(int argc, char const *argv[])
{
    char    dest[50] = {0};
    char    dest2[50] = {0};

    strncpy(dest, "Hello foo", 6);
    ft_strncpy(dest, "Hello foo", 6);

    return (1);
}*/