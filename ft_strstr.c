/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 13:55:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** With implementation **/
/* 	Don't work !
char	*ft_strstr(const char *str, const char *find)
{
	char	c;
	char	sc;
	size_t	len;

	c = *find++;
	if (!c)
		return ((char *) str);

	len = ft_strlen(find);

	while (sc = *str++ != c)
	{
		if (!sc)
			return ((char *) 0);
	}

	while (ft_strncmp(str, find, len))
	{
				
	}
	return ((char *) str - 1);
}
*/

/** Without implementation **/
char	*ft_strstr(const char *str, const char *find)
{
	int	k;
	int	i;

	if (str == 0 || find == 0)
		return (0);
	k = 0;
	i = 0;
	while (str[i] != '\0')
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
