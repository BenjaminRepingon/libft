/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 17:20:00 by rbenjami          #+#    #+#             */
/*   Updated: 2014/05/30 17:21:17 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpytab(char **tab, int lenth)
{
	char	**new_tab;
	int		i;
	int		tablen;

	i = 0;
	tablen = ft_tabsize((void **)tab);
	new_tab = (char **)ft_memalloc(sizeof(char *) * lenth + 1);
	while (i < tablen)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new_tab);
}
