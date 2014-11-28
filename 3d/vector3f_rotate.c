/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:46 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 11:53:57 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3f	*rotate3(t_vector3f *vec, t_vector3f *axis, float angle)
{
	float		sin_angle;
	float		cos_angle;

	sin_angle = (float)sin(-angle);
	cos_angle = (float)cos(-angle);
	vec = cross3(vec, mul3f(axis, sin_angle));
	vec = add3v(vec, mul3f(vec, cos_angle));
	vec = add3v(vec, mul3f(vec, dot3(vec, mul3f(axis, 1 - cos_angle))));
	return (vec);
}

t_vector3f	*rotate3q(t_vector3f *vec, t_quaternion *rotation)
{
	t_quaternion	*conjugate;
	t_quaternion	*w;

	conjugate = conjugate4(rotation);
	w = mul4q(mul4v(rotation, vec), conjugate);
	vec->x = w->x;
	vec->y = w->y;
	vec->z = w->z;
	ft_memdel((void **)&conjugate);
	ft_memdel((void **)&w);
	return (vec);
}
