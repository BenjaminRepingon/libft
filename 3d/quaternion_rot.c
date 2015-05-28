/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:20:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/05/27 15:00:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

MAT4		*to_rotation_matrix(QUAT *q)
{
	MAT4	*mat;
	// VEC3	*forward;
	// VEC3	*up;
	// VEC3	*right;
	// float	xyz[3];

	q = normalized4(q);
	mat = new_matrix4();
	mat->m[0][0] = 1.0f - 2.0f * q->y * q->y - 2.0f * q->z * q->z;
	mat->m[0][1] = 2.0f * q->x * q->y - 2.0f * q->z * q->w;
	mat->m[0][2] = 2.0f * q->x * q->z + 2.0f * q->y * q->w;
	mat->m[0][3] = 0.0f;
	mat->m[1][0] = 2.0f * q->x * q->y + 2.0f * q->z * q->w;
	mat->m[1][1] = 1.0f - 2.0f * q->x * q->x - 2.0f * q->z * q->z;
	mat->m[1][2] = 2.0f * q->y * q->z - 2.0f * q->x * q->w;
	mat->m[1][3] = 0.0f;
	mat->m[2][0] = 2.0f * q->x * q->z - 2.0f * q->y * q->w;
	mat->m[2][1] = 2.0f * q->y * q->z + 2.0f * q->x * q->w;
	mat->m[2][2] = 1.0f - 2.0f * q->x * q->x - 2.0f * q->y * q->y;
	mat->m[2][3] = 0.0f;
	mat->m[3][0] = 0.0f;
	mat->m[3][1] = 0.0f;
	mat->m[3][2] = 0.0f;
	mat->m[3][3] = 1.0f;
	// xyz[0] = 2.0f * (q->x * q->z - q->w * q->y);
	// xyz[1] = 2.0f * (q->y * q->z + q->w * q->x);
	// xyz[2] = 1.0f - 2.0f * (q->x * q->x + q->y * q->y);
	// forward = new_vector3f(xyz[0], xyz[1], xyz[2]);
	// xyz[0] = 2.0f * (q->x * q->y + q->w * q->z);
	// xyz[1] = 1.0f - 2.0f * (q->x * q->x + q->z * q->z);
	// xyz[2] = 2.0f * (q->y * q->z - q->w * q->x);
	// up = new_vector3f(xyz[0], xyz[1], xyz[2]);
	// xyz[0] = 1.0f - 2.0f * (q->y * q->y + q->z * q->z);
	// xyz[1] = 2.0f * (q->x * q->y - q->w * q->z);
	// xyz[2] = 2.0f * (q->x * q->z + q->w * q->y);
	// right = new_vector3f(xyz[0], xyz[1], xyz[2]);
	// mat = init_rotation3v(forward, up, right);
	// ft_memdel((void **)&forward);
	// ft_memdel((void **)&up);
	// ft_memdel((void **)&right);
	return (mat);
}
