/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 11:26:39 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/20 15:15:53 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(void **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		free(tab);
		tab = NULL;
	}
}
