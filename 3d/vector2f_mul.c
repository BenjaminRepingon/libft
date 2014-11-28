/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:54:07 by rbenjami          #+#    #+#             */
/*   Updated: 2014/11/28 12:14:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2f	*mul2f(t_vector2f *vec1, float value)
{
	vec1->x *= value;
	vec1->y *= value;
	return (vec1);
}

t_vector2f	*mul2v(t_vector2f *vec1, t_vector2f *vec2)
{
	vec1->x *= vec2->x;
	vec1->y *= vec2->y;
	return (vec1);
}
