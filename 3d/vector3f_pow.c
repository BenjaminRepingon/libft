/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:52:58 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 11:41:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3f	*pow3f(t_vector3f *vec1, float value)
{
	vec1->x = pow(vec1->x, value);
	vec1->y = pow(vec1->y, value);
	vec1->z = pow(vec1->z, value);
	return (vec1);
}

t_vector3f	*rt3(t_vector3f *vec1)
{
	return (mul3v(vec1, vec1));
}
