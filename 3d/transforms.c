/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:05:39 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 11:59:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3f		*transform(t_vector3f *v, t_matrix4f *m)
{
	float	x;
	float	y;
	float	z;

	x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z + m->m[0][3];
	y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z + m->m[1][3];
	z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z + m->m[2][3];
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vector3f		*get_transforms(t_vector3f *v, t_vector3f *t, t_quaternion *r)
{
	t_matrix4f	*m;

	m = to_rotation_matrix(r);
	m = mul4m(m, init_translation(t));
	v = transform(v, m);
	ft_memdel((void **)&m);
	return (v);
}
