/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:07:42 by rbenjami          #+#    #+#             */
/*   Updated: 2015/06/04 14:18:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_list(void)
{
	t_list	*list;

	if ((list = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_elem	*add_elem(t_list *list, void *data)
{
	t_elem	*elem;

	if ((elem = (t_elem *)ft_memalloc(sizeof(t_elem))) == NULL)
		return (NULL);
	elem->next = NULL;
	elem->data = data;
	list->size += 1;
	if (list->first == NULL)
		list->first = elem;
	if (list->last != NULL)
		list->last->next = elem;
	list->last = elem;
	return (elem);
}

t_elem	*get_elem(t_list *list, size_t index)
{
	size_t	i;
	t_elem	*elem;

	i = 0;
	elem = list->first;
	while (i < index)
	{
		i++;
		elem = elem->next;
	}
	return (elem);
}

void	del_list(t_list *list)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = list->first;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		ft_memdel(&tmp->data);
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&list);
}
