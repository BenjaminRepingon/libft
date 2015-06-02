/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:45:21 by rbenjami          #+#    #+#             */
/*   Updated: 2015/06/02 14:46:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VEC3	vector3f(float x, float y, float z)
{
	VEC3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
