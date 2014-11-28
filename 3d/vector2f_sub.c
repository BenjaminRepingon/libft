/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:53:30 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 12:19:57 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2f	*sub2f(t_vector2f *vec1, float value)
{
	vec1->x -= value;
	vec1->y -= value;
	return (vec1);
}

t_vector2f	*sub2v(t_vector2f *vec1, t_vector2f *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	return (vec1);
}

t_vector2f	*inv2(t_vector2f *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	return (vec);
}
