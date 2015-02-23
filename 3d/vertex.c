/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:26:16 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/19 10:50:57 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VERT		*new_vertex3f(float x, float y, float z)
{
	VERT	*vertex;

	if ((vertex = (VERT *)ft_memalloc(sizeof(VERT))) == NULL)
		return (NULL);
	vertex->pos.x = x;
	vertex->pos.y = y;
	vertex->pos.z = z;
	vertex->color.x = 0xFF;
	vertex->color.y = 0xFF;
	vertex->color.z = 0xFF;
	return (vertex);
}

VERT		*new_vertexp(VEC3 pos)
{
	VERT	*vertex;

	if ((vertex = (VERT *)ft_memalloc(sizeof(VERT))) == NULL)
		return (NULL);
	vertex->pos.x = pos.x;
	vertex->pos.y = pos.y;
	vertex->pos.z = pos.z;
	vertex->color.x = 0xFF;
	vertex->color.y = 0xFF;
	vertex->color.z = 0xFF;
	return (vertex);
}

VERT		*new_vertexpc(VEC3 pos, VEC3 color)
{
	VERT	*vertex;

	if ((vertex = (VERT *)ft_memalloc(sizeof(VERT))) == NULL)
		return (NULL);
	vertex->pos.x = pos.x;
	vertex->pos.y = pos.y;
	vertex->pos.z = pos.z;
	vertex->color.x = color.x;
	vertex->color.y = color.y;
	vertex->color.z = color.z;
	return (vertex);
}
