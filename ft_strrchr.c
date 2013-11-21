/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 13:55:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *cp, int ch)
{
	char	*save;
	char	c;

	save = (char *) 0;
	while ((c = *cp))
	{
		cp++;
		if (c == ch)
			save = (char *) cp;
	}
	return (save);
}