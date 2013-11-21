/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/19 13:55:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	/*if (*str == '\0')
		return 0;

	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + str[i] - '0';
		++i;
	}

	return sign * res;*/
	return (int)*str;
}
/*
int main()
{
  char str[]="1776ad";
  int year;
  if (ft_isdigit(str[0]))
  {
    year = ft_atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
  return 0;
}*/