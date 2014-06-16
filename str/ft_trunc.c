/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:36:16 by rbenjami          #+#    #+#             */
/*   Updated: 2014/06/16 17:57:08 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static void		add_char(char **res, char c)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_memalloc(2);
	tmp[0] = c;
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

static void		add_str(char **res, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(str);
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

static void		add_int(char **res, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(i);
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

char			*ft_trunc(const char *msg, ...)
{
	va_list		ap;
	char		*res;

	res = NULL;
	va_start(ap, msg);
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			if (*msg == '%')
				add_char(&res, va_arg(ap, int));
			else if (*msg == 'c')
				add_char(&res, va_arg(ap, int));
			else if (*msg == 's')
				add_str(&res, va_arg(ap, char *));
			else if (*msg == 'd' || *msg == 'i')
				add_int(&res, va_arg(ap, int));
		}
		else
			add_char(&res, *msg);
		msg++;
	}
	va_end(ap);
	return (res);
}
