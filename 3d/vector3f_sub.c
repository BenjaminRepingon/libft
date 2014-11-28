/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:29:27 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 11:39:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3f	*sub3f(t_vector3f *vec1, float value)
{
	vec1->x -= value;
	vec1->y -= value;
	vec1->z -= value;
	return (vec1);
}

t_vector3f	*sub3v(t_vector3f *vec1, t_vector3f *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	vec1->z -= vec2->z;
	return (vec1);
}

t_vector3f	*inv3(t_vector3f *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
	return (vec);
}
